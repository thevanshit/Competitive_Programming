#!/usr/bin/env python3
"""
update_stats.py — Scan solution files and auto-update README stats.

Reads .solved_state.json (totals + disk baseline), scans current .cpp files,
computes delta from baseline, updates totals, rewrites README, saves state.

Usage: python3 scripts/update_stats.py
       (Run from the repo root, or script auto-detects it.)
"""

import json
import os
import re
import sys
from pathlib import Path
from typing import Dict, Tuple

# ── Paths ──────────────────────────────────────────────────────────
REPO_ROOT = Path(__file__).resolve().parent.parent
STATE_FILE = REPO_ROOT / ".solved_state.json"
README_FILE = REPO_ROOT / "README.md"

# ── Categories to track ────────────────────────────────────────────
# Each category: (glob_pattern, key_in_state)
SCAN_SPECS: Dict[str, Tuple[str, str]] = {
    "codeforces_contests": ("codeforces/contests/**/*.cpp", "codeforces_contests"),
    "codeforces_rated_900_1000": ("codeforces/rated/900-1000/*.cpp", "codeforces_rated_900_1000"),
    "codeforces_rated_1000_1100": ("codeforces/rated/1000-1100/*.cpp", "codeforces_rated_1000_1100"),
    "codeforces_rated_1100_1200": ("codeforces/rated/1100-1200/*.cpp", "codeforces_rated_1100_1200"),
    "codeforces_rated_1900_2000": ("codeforces/rated/1900 - 2000/*.cpp", "codeforces_rated_1900_2000"),
    "codechef": ("codechef/**/*.cpp", "codechef"),
    "atcoder": ("atcoder/**/*.cpp", "atcoder"),
}

RATED_KEYS = [
    "codeforces_rated_900_1000",
    "codeforces_rated_1000_1100",
    "codeforces_rated_1100_1200",
    "codeforces_rated_1900_2000",
]


# ── Helpers ────────────────────────────────────────────────────────

def scan_disk() -> Dict[str, int]:
    """Count .cpp files per category on disk."""
    counts: Dict[str, int] = {}
    for category, (glob_pat, _key) in SCAN_SPECS.items():
        files = list(REPO_ROOT.glob(glob_pat))
        counts[category] = len(files)
    return counts


def load_state() -> dict:
    """Load state file, or initialise with defaults if missing/corrupt."""
    if STATE_FILE.exists():
        try:
            with open(STATE_FILE) as f:
                return json.load(f)
        except (json.JSONDecodeError, KeyError):
            print("⚠️  Corrupt state file. Reinitialising from disk...")
    return _initial_state()


def _initial_state() -> dict:
    """Build a fresh state from current disk counts (totals == disk counts)."""
    disk = scan_disk()
    return {"totals": dict(disk), "disk_baseline": dict(disk)}


def save_state(state: dict) -> None:
    with open(STATE_FILE, "w") as f:
        json.dump(state, f, indent=2)
        f.write("\n")


def compute_totals(state: dict, disk: dict) -> Dict[str, int]:
    """Apply delta from baseline to produce new lifetime totals."""
    old_totals = state["totals"]
    baseline = state["disk_baseline"]
    new_totals: Dict[str, int] = {}
    for key in old_totals:
        delta = disk.get(key, 0) - baseline.get(key, 0)
        new_totals[key] = max(old_totals[key] + delta, 0)
    return new_totals


def derived(totals: Dict[str, int]) -> Dict[str, int]:
    """Derive roll-up values from per-category totals."""
    rated = sum(totals[k] for k in RATED_KEYS)
    cf_contest = totals["codeforces_contests"]
    cf_total = cf_contest + rated
    return {
        "codeforces": cf_total,
        "codeforces_rated": rated,
        "codeforces_contest": cf_contest,
        "codechef": totals["codechef"],
        "atcoder": totals["atcoder"],
        "grand_total": cf_total + totals["codechef"] + totals["atcoder"],
    }


# ── README updaters ────────────────────────────────────────────────

def update_readme(totals: Dict[str, int]) -> None:
    """Update every stats section in README.md in-place."""
    d = derived(totals)
    rated_bar = [str(totals[k]) for k in RATED_KEYS]

    with open(README_FILE) as f:
        text = f.read()

    # 1. Badges (shields.io URLs)
    text = re.sub(
        r'badge/Solutions-\d+-blue',
        f'badge/Solutions-{d["grand_total"]}-blue',
        text,
    )
    text = re.sub(
        r'badge/CodeForces-\d+-red',
        f'badge/CodeForces-{d["codeforces"]}-red',
        text,
    )
    text = re.sub(
        r'badge/CodeChef-\d+-brown',
        f'badge/CodeChef-{d["codechef"]}-brown',
        text,
    )
    text = re.sub(
        r'badge/AtCoder-\d+-blue',
        f'badge/AtCoder-{d["atcoder"]}-blue',
        text,
    )

    # 2. Stats block
    text = re.sub(
        r'Total Problems Solved:  \d+',
        f'Total Problems Solved:  {d["grand_total"]}',
        text,
    )

    # 3. Platform breakdown table rows
    # CodeForces row
    text = re.sub(
        r'\| \[CodeForces\]\(https://codeforces\.com\) \| \d+ \| \d+ \| \*\*\d+\*\* \|',
        f'| [CodeForces](https://codeforces.com) | {d["codeforces_contest"]} | {d["codeforces_rated"]} | **{d["codeforces"]}** |',
        text,
    )
    # CodeChef row
    text = re.sub(
        r'\| \[CodeChef\]\(https://www\.codechef\.com\) \| \d+ \| -- \| \*\*\d+\*\* \|',
        f'| [CodeChef](https://www.codechef.com) | {d["codechef"]} | -- | **{d["codechef"]}** |',
        text,
    )
    # AtCoder row
    text = re.sub(
        r'\| \[AtCoder\]\(https://atcoder\.jp\) \| \d+ \| -- \| \*\*\d+\*\* \|',
        f'| [AtCoder](https://atcoder.jp) | {d["atcoder"]} | -- | **{d["atcoder"]}** |',
        text,
    )
    # Total row
    contest_sum = d["codeforces_contest"] + d["codechef"] + d["atcoder"]
    text = re.sub(
        r'\| \*\*Total\*\* \| \*\*\d+\*\* \| \*\*\d+\*\* \| \*\*\d+\*\* \|',
        f'| **Total** | **{contest_sum}** | **{d["codeforces_rated"]}** | **{d["grand_total"]}** |',
        text,
    )

    # 4. Mermaid chart bar
    bar_str = ", ".join(rated_bar)
    text = re.sub(
        r'bar \[\d+, \d+, \d+, \d+\]',
        f'bar [{bar_str}]',
        text,
    )

    # 5. Difficulty table rows
    text = re.sub(
        r'\| 900 - 1000 \| \d+ \| Beginner \|',
        f'| 900 - 1000 | {totals["codeforces_rated_900_1000"]} | Beginner |',
        text,
    )
    text = re.sub(
        r'\| 1100 - 1200 \| \d+ \| Medium \|',
        f'| 1100 - 1200 | {totals["codeforces_rated_1100_1200"]} | Medium |',
        text,
    )

    # 6. Repo structure directory counts
    text = re.sub(
        r'\|-- codeforces/                     # \d+ solutions',
        f'|-- codeforces/                     # {d["codeforces"]} solutions',
        text,
    )
    text = re.sub(
        r'\|       \|-- 900-1000/               # \d+ problems \(Newbie\)',
        f'|       |-- 900-1000/               # {totals["codeforces_rated_900_1000"]} problems (Newbie)',
        text,
    )
    text = re.sub(
        r'\|       \|-- 1100-1200/              # \d+ problems \(Specialist\)',
        f'|       |-- 1100-1200/              # {totals["codeforces_rated_1100_1200"]} problems (Specialist)',
        text,
    )
    text = re.sub(
        r'\|-- codechef/                       # \d+ solutions',
        f'|-- codechef/                       # {d["codechef"]} solutions',
        text,
    )
    text = re.sub(
        r'\|-- atcoder/                        # \d+ solutions',
        f'|-- atcoder/                        # {d["atcoder"]} solutions',
        text,
    )

    # 7. Goals / progress — "X+ problems solved"
    text = re.sub(
        r'- \[x\] \d+\+ problems solved',
        f'- [x] {d["grand_total"]}+ problems solved',
        text,
    )
    # Also update the subtitle
    text = re.sub(
        r'arsenal -- \d+\+ solutions',
        f'arsenal -- {d["grand_total"]}+ solutions',
        text,
    )

    with open(README_FILE, "w") as f:
        f.write(text)


# ── Main ───────────────────────────────────────────────────────────

def main() -> None:
    os.chdir(REPO_ROOT)

    state = load_state()
    disk = scan_disk()

    old_totals = state["totals"]
    new_totals = compute_totals(state, disk)

    # Check for any net change
    changed = any(new_totals[k] != old_totals[k] for k in old_totals)
    if not changed:
        print("✓ Stats unchanged — no new solution files detected.")
        return

    # Print delta
    print("📊 Stats update detected:")
    for key in old_totals:
        delta = new_totals[key] - old_totals[key]
        if delta:
            print(f"   {key}: {old_totals[key]} → {new_totals[key]} (+{delta})")

    # Update README
    update_readme(new_totals)

    # Save new state
    state["totals"] = new_totals
    state["disk_baseline"] = disk
    save_state(state)

    d = derived(new_totals)
    print(f"✅ README updated — grand total: {d['grand_total']} problems")


if __name__ == "__main__":
    main()
