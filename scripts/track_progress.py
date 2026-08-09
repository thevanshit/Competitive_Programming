#!/usr/bin/env python3
"""
track_progress.py — Auto-update the roadmap progress tables.

Scans solution files on disk, merges manual overrides from roadmap/.progress.json,
and rewrites the tracker tables in roadmap/CANDIDATE_MASTER_2026.md.

Usage:
    python3 scripts/track_progress.py            # scan disk + manual overrides
    python3 scripts/track_progress.py --fetch    # also fetch CF rating from API
       (Run from the repo root, or script auto-detects it.)
"""

import json
import os
import re
import ssl
import sys
import urllib.request
from pathlib import Path
from typing import Dict, List, Optional, Tuple

# ── Paths ──────────────────────────────────────────────────────────
REPO_ROOT = Path(__file__).resolve().parent.parent
ROADMAP_FILE = REPO_ROOT / "roadmap" / "CANDIDATE_MASTER_2026.md"
PROGRESS_FILE = REPO_ROOT / "roadmap" / ".progress.json"

# ── CP-31 tiers: (tier_label, disk_glob, state_key) ────────────────
# Tiers with a disk folder are auto-counted; others come from .progress.json.
CP31_TIERS: Dict[str, Tuple[Optional[str], str]] = {
    "900-1000": ("codeforces/rated/900-1000/*.cpp", "cp31_900"),
    "1000-1100": ("codeforces/rated/1000-1100/*.cpp", "cp31_1000"),
    "1100-1200": ("codeforces/rated/1100-1200/*.cpp", "cp31_1100"),
    "1300": (None, "cp31_1300"),
    "1400": (None, "cp31_1400"),
    "1500": (None, "cp31_1500"),
    "1600": (None, "cp31_1600"),
    "1700": (None, "cp31_1700"),
    "1800": (None, "cp31_1800"),
    "1900": (None, "cp31_1900"),
    "1900+": ("codeforces/rated/1900 - 2000/*.cpp", "cp31_1900plus"),
}

CP31_TOTAL = 31  # problems per tier

# ── CSES sections: (section_label, disk_folder) ────────────────────
CSES_SECTIONS: List[Tuple[str, str]] = [
    ("Introductory", "Introductory Problems"),
    ("Sorting & Searching", "Sorting and Searching"),
    ("Dynamic Programming", "Dynamic Programming"),
    ("Graph Algorithms", "Graph Algorithms"),
    ("Range Queries", "Range Queries"),
    ("Tree Algorithms", "Tree Algorithms"),
    ("Mathematics", "Mathematics"),
    ("String Algorithms", "String Algorithms"),
]

CSES_TOTALS: Dict[str, int] = {
    "Introductory": 19,
    "Sorting & Searching": 35,
    "Dynamic Programming": 19,
    "Graph Algorithms": 36,
    "Range Queries": 19,
    "Tree Algorithms": 16,
    "Mathematics": 31,
    "String Algorithms": 17,
}


# ── Helpers ────────────────────────────────────────────────────────

def scan_disk() -> Dict[str, int]:
    """Count .cpp files per CP-31 tier and CSES section on disk."""
    counts: Dict[str, int] = {}
    for tier, (glob_pat, _key) in CP31_TIERS.items():
        counts[f"cp31_{tier}"] = len(list(REPO_ROOT.glob(glob_pat))) if glob_pat else 0
    for label, folder in CSES_SECTIONS:
        counts[f"cses_{label}"] = len(list(REPO_ROOT.glob(f"cses/{folder}/*.cpp")))
    return counts


def load_progress() -> dict:
    """Load manual overrides, or initialise with defaults if missing."""
    if PROGRESS_FILE.exists():
        try:
            with open(PROGRESS_FILE) as f:
                return json.load(f)
        except (json.JSONDecodeError, KeyError):
            print("WARNING: Corrupt progress file. Reinitialising...")
    return {"cp31": {}, "cses": {}, "ratings": {}}


def save_progress(progress: dict) -> None:
    with open(PROGRESS_FILE, "w") as f:
        json.dump(progress, f, indent=2)
        f.write("\n")


def fetch_cf_rating(handle: str) -> Optional[int]:
    """Fetch current Codeforces rating from the public API."""
    url = f"https://codeforces.com/api/user.info?handles={handle}"
    req = urllib.request.Request(url, headers={"User-Agent": "track_progress/1.0"})
    try:
        # Use certifi CA bundle if available (fixes macOS SSL issues)
        try:
            import certifi
            ctx = ssl.create_default_context(cafile=certifi.where())
        except ImportError:
            ctx = ssl.create_default_context()
        with urllib.request.urlopen(req, timeout=10, context=ctx) as resp:
            data = json.load(resp)
        return data["result"][0].get("rating")
    except Exception:
        return None


# ── Table updaters ─────────────────────────────────────────────────

def update_cp31_table(text: str, disk: Dict[str, int], manual: dict) -> str:
    """Rewrite the CP-31 completion table rows."""
    for tier, (_glob, key) in CP31_TIERS.items():
        done = manual.get(key, disk.get(f"cp31_{tier}", 0))
        remaining = max(CP31_TOTAL - done, 0)
        target = "Done" if remaining == 0 else _target_for(tier)
        row = f"| {tier} | {CP31_TOTAL} | {done} | {remaining} | {target} |"
        text = re.sub(
            rf"\| {re.escape(tier)} \| \d+ \| [\d~]+ \| [\d~]+ \| [^|]* \|",
            row,
            text,
        )
    return text


def _target_for(tier: str) -> str:
    """Map tier to its target date from the roadmap."""
    targets = {
        "900-1000": "Done",
        "1000-1100": "Done",
        "1100-1200": "Aug 15",
        "1300": "Aug 15",
        "1400": "Aug 22",
        "1500": "Aug 29",
        "1600": "Sep 5",
        "1700": "Sep 12",
        "1800": "Sep 19",
        "1900": "Sep 22",
        "1900+": "Sep 25",
    }
    return targets.get(tier, "Sep 25")


def update_cses_table(text: str, disk: Dict[str, int], manual: dict) -> str:
    """Rewrite the CSES sections table rows."""
    for label, folder in CSES_SECTIONS:
        total = CSES_TOTALS[label]
        done = manual.get(f"cses_{label}", disk.get(f"cses_{label}", 0))
        row = f"| {label} | {total} | {done} | {_cses_target(label)} |"
        text = re.sub(
            rf"\| {re.escape(label)} \| \d+ \| [\d~]+ \| [^|]* \|",
            row,
            text,
        )
    return text


def _cses_target(label: str) -> str:
    targets = {
        "Introductory": "Aug 15",
        "Sorting & Searching": "Aug 22",
        "Dynamic Programming": "**Aug 22**",
        "Graph Algorithms": "**Aug 29**",
        "Range Queries": "Sep 12",
        "Tree Algorithms": "Sep 12",
        "Mathematics": "**Sep 5**",
        "String Algorithms": "Sep 12",
    }
    return targets.get(label, "Sep 12")


def update_rating_table(text: str, ratings: dict) -> str:
    """Rewrite the rating tracker row for Codeforces (others stay manual)."""
    cf = ratings.get("codeforces")
    if cf is None:
        return text
    text = re.sub(
        r"\| Codeforces \| \d+ \|",
        f"| Codeforces | {cf} |",
        text,
    )
    return text


# ── Main ───────────────────────────────────────────────────────────

def main() -> None:
    os.chdir(REPO_ROOT)
    fetch = "--fetch" in sys.argv

    progress = load_progress()
    disk = scan_disk()
    manual = progress.get("manual", {})

    with open(ROADMAP_FILE) as f:
        text = f.read()

    text = update_cp31_table(text, disk, manual)
    text = update_cses_table(text, disk, manual)

    if fetch:
        rating = fetch_cf_rating("thevanshit")
        if rating is not None:
            progress.setdefault("ratings", {})["codeforces"] = rating
            text = update_rating_table(text, progress["ratings"])
            print(f"Codeforces rating fetched: {rating}")
        else:
            print("WARNING: Could not fetch Codeforces rating (offline?).")

    with open(ROADMAP_FILE, "w") as f:
        f.write(text)

    save_progress(progress)

    # Summary
    print("Roadmap progress tables updated:")
    for tier, (_glob, key) in CP31_TIERS.items():
        done = manual.get(key, disk.get(f"cp31_{tier}", 0))
        print(f"   CP-31 {tier}: {done}/{CP31_TOTAL}")
    for label, folder in CSES_SECTIONS:
        done = manual.get(f"cses_{label}", disk.get(f"cses_{label}", 0))
        print(f"   CSES {label}: {done}/{CSES_TOTALS[label]}")


if __name__ == "__main__":
    main()