#!/usr/bin/env python3
"""
generate_calendar.py — Export the ICPC+GSoC 2027 master plan as a Google Calendar CSV.

Generates every study block, contest slot, and milestone from
roadmap/ICPC_GSOC_MASTER_2027.md as explicit events (Google's CSV importer
does not support recurrence rules, so each occurrence is a row).

Usage:
    python3 scripts/generate_calendar.py
       (Run from the repo root, or script auto-detects it.)

Output:
    roadmap/icpc_gsoc_calendar.csv  — import into Google Calendar:
        Settings -> Import & Export -> Import -> select CSV -> pick calendar
"""

import csv
from datetime import date, datetime, timedelta
from pathlib import Path
from typing import Dict, List, Tuple

# ── Paths ──────────────────────────────────────────────────────────
REPO_ROOT = Path(__file__).resolve().parent.parent
OUT_FILE = REPO_ROOT / "roadmap" / "icpc_gsoc_calendar.csv"

# ── Plan window ────────────────────────────────────────────────────
START = date(2026, 8, 15)
END = date(2027, 9, 25)  # inclusive

# ── Phase boundaries ───────────────────────────────────────────────
PHASE_A_END = date(2026, 9, 25)   # CP sprint
PHASE_B_END = date(2026, 12, 31)  # ICPC 26-27 season + GSoC S1-2
PHASE_C_END = date(2027, 3, 31)   # GSoC application season
PHASE_D_END = date(2027, 8, 31)   # GSoC coding period
# Phase E: Sep 1 - Sep 25, 2027 (ICPC 27-28 peak)

# ── Phase A weekly focus (Saturday start dates) ────────────────────
PHASE_A_WEEKS: List[Tuple[date, str]] = [
    (date(2026, 8, 15), "Foundation: sorting, binary search, two pointers, STL (CSES Ch 1-4, CP4 B1 Ch 1-2)"),
    (date(2026, 8, 22), "Dynamic Programming (CSES Ch 7, CP4 B1 Ch 3.4 pp 153-215)"),
    (date(2026, 8, 29), "Graphs & Trees: BFS/DFS/Dijkstra/MST/DSU (CSES Ch 11-14, CP4 B1 Ch 4)"),
    (date(2026, 9, 5), "Math: modular arithmetic, combinatorics, number theory (CP4 B1 Ch 5.3-5.6)"),
    (date(2026, 9, 12), "Advanced DS + Strings: seg tree, BIT, KMP, hashing (CP4 B1 Ch 6, CP4 B2 Ch 9 skim)"),
    (date(2026, 9, 19), "PEAK: 1800-1900+ tiers, finals push, review"),
]

# ── Milestones (all-day events) ────────────────────────────────────
MILESTONES: List[Tuple[date, str]] = [
    (date(2026, 8, 15), "START: ICPC + GSoC 2027 Master Plan — CP sprint begins"),
    (date(2026, 8, 20), "ICPC TASK: Recruit 2 teammates (start today, done by Aug 20)"),
    (date(2026, 8, 27), "ICPC TASK: Confirm faculty coach (ask CS/HOD dept)"),
    (date(2026, 9, 15), "ICPC TASK: Register team + submit payment (before Sep 21 cutoff)"),
    (date(2026, 9, 21), "DEADLINE: ICPC India registration closes (team + coach + payment)"),
    (date(2026, 9, 25), "CP CURRICULUM COMPLETE — books, CP-31 100%, CSES core, ~20 contests"),
    (date(2026, 10, 10), "ICPC 2026-27 India Preliminary (online) — exact date on portal"),
    (date(2026, 12, 11), "ICPC Chennai Regional (Dec 11-12)"),
    (date(2026, 12, 18), "ICPC Dhaka Regional (Dec 18-19)"),
    (date(2026, 12, 22), "ICPC Kanpur Regional (Dec 22-23)"),
    (date(2026, 12, 27), "ICPC Mathura Regional (Dec 27-28)"),
    (date(2026, 12, 30), "ICPC Amritapuri Regional (end Dec)"),
    (date(2027, 1, 1), "Phase C begins: GSoC application season — Stage 3 (ML & DL) + org research"),
    (date(2027, 1, 31), "GSoC TASK: Org shortlist finalized (8-10 orgs -> 3 targets)"),
    (date(2027, 2, 19), "GSoC 2027 accepted orgs announced — start contributions TODAY"),
    (date(2027, 3, 10), "GSoC TASK: Proposal drafts done, feedback from mentors/community"),
    (date(2027, 3, 16), "GSoC application window OPENS — submit early (Mar 16-20)"),
    (date(2027, 3, 20), "AWC Championship (Mar 20-21) — if qualified"),
    (date(2027, 3, 31), "DEADLINE: GSoC proposals due 18:00 UTC"),
    (date(2027, 4, 30), "GSoC 2027 results announced"),
    (date(2027, 5, 1), "Community bonding period (May 1-24) — repo dive, env setup, mentor calls"),
    (date(2027, 5, 25), "GSoC CODING BEGINS (May 25 - Aug 24)"),
    (date(2027, 7, 6), "GSoC midterm evaluations (Jul 6-10)"),
    (date(2027, 8, 24), "GSoC final evaluations (Aug 24-31)"),
    (date(2027, 8, 31), "GSoC 2027 DONE — final eval passed"),
    (date(2027, 9, 1), "Phase E begins: ICPC 2027-28 peak — team virtuals + old Asia West sets"),
    (date(2027, 9, 10), "ICPC TASK: Confirm 2027-28 team registration (check portal for window)"),
    (date(2027, 9, 25), "MISSION COMPLETE — ready for ICPC 2027-28 prelims"),
]

# ── Helpers ────────────────────────────────────────────────────────
def phase_of(d: date) -> str:
    if d <= PHASE_A_END:
        return "A"
    if d <= PHASE_B_END:
        return "B"
    if d <= PHASE_C_END:
        return "C"
    if d <= PHASE_D_END:
        return "D"
    return "E"


def phase_a_week(d: date) -> str:
    """Return 'W1'..'W6' for Phase A dates, else ''."""
    if phase_of(d) != "A":
        return ""
    for i, (start, _) in enumerate(PHASE_A_WEEKS, start=1):
        if start <= d < start + timedelta(days=7):
            return f"W{i}"
    return ""


def phase_a_focus(d: date) -> str:
    for start, focus in PHASE_A_WEEKS:
        if start <= d < start + timedelta(days=7):
            return focus
    return ""


def fmt_time(h: int, m: int) -> str:
    """12-hour clock with AM/PM (Google CSV format)."""
    return datetime(2000, 1, 1, h, m).strftime("%I:%M %p").lstrip("0")


def fmt_date(d: date) -> str:
    return d.strftime("%m/%d/%Y")


# ── Event builders ─────────────────────────────────────────────────
def add_block(rows: List[List[str]], d: date, start: Tuple[int, int],
              end: Tuple[int, int], subject: str, desc: str = "") -> None:
    """Add a timed event on day d."""
    rows.append([
        subject,
        fmt_date(d), fmt_time(*start),
        fmt_date(d), fmt_time(*end),
        "False", desc, "", "False",
    ])


def add_all_day(rows: List[List[str]], d: date, subject: str, desc: str = "") -> None:
    rows.append([subject, fmt_date(d), "", fmt_date(d), "", "True", desc, "", "False"])


# ── Daily block subjects per phase ─────────────────────────────────
def morning_subject(d: date) -> Tuple[str, str]:
    p = phase_of(d)
    if p == "A":
        w = phase_a_week(d)
        return (f"READING {w}: CP books + CP-Algorithms",
                f"Phase A {w} focus: {phase_a_focus(d)}. ~23 pages/day (CSES Handbook, CP4 B1, CP4 B2).")
    if p == "B":
        return ("GSoC Stage 1-2: Git + Python + Stats",
                "Head First Git -> Fluent Python -> pytest -> Practical Statistics. 3 OSS PRs by Dec 31.")
    if p == "C":
        return ("GSoC Stage 3-4: ML/DL + Transformers",
                "Hands-On ML, DL from Scratch, NLP with Transformers, Build LLM from Scratch. Proposals by Mar 31.")
    if p == "D":
        return ("GSoC Stage 5-6: LLM Apps + Agents",
                "Prompt Eng, RAG, AI Engineering, Agents/MCP, LLMOps. Coding period is the priority.")
    return ("CP review: notes + re-solves",
            "Phase E: re-read notes, re-solve 10 failed problems, template audit.")


def evening_subject(d: date) -> Tuple[str, str]:
    p = phase_of(d)
    if p == "A":
        return ("GRIND: CP-31 + CSES",
                f"Phase A {phase_a_week(d)}: 4 CP-31 + 3-4 CSES. 45-min rule, then editorial.")
    if p == "B":
        return ("CP maintenance + team practice",
                "3 contests/week + upsolve hardest miss. Team virtuals on weekends (ICPC format).")
    if p == "C":
        return ("GSoC: org research / contributions / proposals",
                "Jan: shortlist orgs. Feb 19+: PRs to target orgs. Mar 16-31: submit proposals.")
    if p == "D":
        return ("GSoC project coding",
                "Milestone work + tests + docs. Weekly mentor sync. 1 contest/week only.")
    return ("ICPC team virtuals + mixed marathons",
            "Phase E: 3 ICPC-format virtuals/week, old Asia West sets, role drills.")


def evening2_subject(d: date) -> Tuple[str, str]:
    """The 19:00-21:00 slot — varies by weekday and phase."""
    p = phase_of(d)
    wd = d.weekday()  # 0=Mon .. 6=Sun
    if p == "A":
        if wd == 0:
            return ("Topic practice", "Weakest topic deep-dive (Striver/USACO/CP-Algorithms).")
        if wd == 1:
            return ("Codeforces contest (check TLE tracker)", "CF ~20:05/22:35 IST. Full upsolve after.")
        if wd == 2:
            return ("CodeChef Starters", "Wed 20:00 IST. Solve 4-5, then upsolve.")
        if wd == 3:
            return ("Upsolve Tue/Wed contests", "1 hr per missed problem, then editorial, then code from scratch.")
        return ("Topic deep-dive", "Missing topics: DP/Graph/Strings per week focus.")
    if p == "B":
        if wd == 1:
            return ("Codeforces contest", "CF ~20:05/22:35 IST. Upsolve hardest miss only.")
        if wd == 2:
            return ("CodeChef Starters", "Wed 20:00 IST.")
        if wd == 3:
            return ("Upsolve + team strategy", "Review contest misses + plan weekend team virtuals.")
        return ("GSoC Stage 1-2 books", "Git/Python/OSS reading — 3 PRs by Dec 31.")
    if p == "C":
        if wd == 1:
            return ("Codeforces contest", "CF ~20:05/22:35 IST.")
        if wd == 2:
            return ("CodeChef Starters", "Wed 20:00 IST.")
        if wd == 3:
            return ("GSoC community engagement", "Discord/Matrix, review others' PRs, ask on issues.")
        return ("GSoC Stage 3-4 books", "ML/DL/Transformers reading for proposal credibility.")
    if p == "D":
        if wd == 2:
            return ("CodeChef Starters (only contest this week)", "Wed 20:00 IST — keeps you warm.")
        return ("GSoC coding", "Project work. If not accepted: portfolio projects + Stages 5-6.")
    # Phase E
    if wd == 1:
        return ("Codeforces contest", "CF ~20:05/22:35 IST.")
    if wd == 2:
        return ("CodeChef Starters", "Wed 20:00 IST.")
    if wd == 3:
        return ("Upsolve + team drills", "Contest misses + ICPC role practice.")
    return ("Mixed-topic marathon", "Old ICPC Asia West sets (Amritapuri/Kanpur archives).")


def weekend_subject(d: date) -> List[Tuple[Tuple[int, int], Tuple[int, int], str, str]]:
    """Return list of (start, end, subject, desc) blocks for a weekend day."""
    p = phase_of(d)
    wd = d.weekday()  # 5=Sat, 6=Sun
    blocks = []
    if p == "A":
        blocks = [
            ((8, 0), (10, 30), "Reading catch-up", "Missed book pages from the week."),
            ((10, 30), (13, 0), "CP-31 grind", "Highest remaining tier — 4-5 problems."),
            ((13, 0), (16, 0), "CSES section", "3-4 problems, untimed, deeper thinking."),
        ]
        if wd == 5:
            blocks.append(((16, 30), (21, 30), "AtCoder ABC (17:30 IST) + upsolve",
                           "A-D target. Full upsolve of misses."))
        else:
            blocks.append(((16, 30), (19, 30), "Virtual CF Div2 simulation", "2h timed, then full upsolve."))
            blocks.append(((21, 30), (22, 0), "Weekly review + tracker update",
                           "Fill Section 11 check-in. Plan next week's 3 focus items."))
    elif p == "B":
        blocks = [
            ((8, 0), (10, 30), "GSoC Stage 1-2 books", "Git/Python/Stats reading."),
            ((10, 30), (13, 0), "Team virtual #1 (ICPC format)", "3-persons-1-machine practice."),
            ((13, 0), (16, 0), "Upsolve + role specialization", "Implementation / math / graphs roles."),
        ]
        if wd == 5:
            blocks.append(((17, 30), (20, 30), "AtCoder ABC", "A-D target."))
        else:
            blocks.append(((16, 30), (19, 30), "Team virtual #2 + Virtual CF", "ICPC-format reps."))
            blocks.append(((21, 30), (22, 0), "Weekly review + tracker update", "All 3 tracks check-in."))
    elif p == "C":
        blocks = [
            ((8, 0), (10, 30), "GSoC Stage 3-4 books", "ML/DL/Transformers."),
            ((10, 30), (13, 0), "GSoC contributions", "PRs to target orgs (Feb 19+)."),
            ((13, 0), (16, 0), "GSoC books / proposal drafts", "Mar: write proposals, get community feedback."),
        ]
        if wd == 5:
            blocks.append(((17, 30), (20, 30), "AtCoder ABC", "A-D target."))
        else:
            blocks.append(((16, 30), (19, 30), "Virtual CF Div2", "2h timed."))
            blocks.append(((21, 30), (22, 0), "Weekly review + tracker update", "GSoC milestone progress."))
    elif p == "D":
        blocks = [
            ((8, 0), (10, 30), "GSoC Stage 5-6 books", "LLM Apps, Agents, LLMOps."),
            ((10, 30), (13, 0), "GSoC coding", "Milestone work."),
            ((13, 0), (16, 0), "GSoC coding", "Milestone work + tests."),
        ]
        if wd == 5:
            blocks.append(((17, 30), (20, 30), "AtCoder ABC (only contest)", "Keeps you warm."))
        else:
            blocks.append(((16, 30), (19, 30), "GSoC coding", "Milestone work."))
            blocks.append(((21, 30), (22, 0), "Weekly review + tracker update", "GSoC milestone progress."))
    else:  # Phase E
        blocks = [
            ((8, 0), (10, 30), "CP review", "Notes re-read, template audit."),
            ((10, 30), (13, 0), "ICPC-format virtual", "3-persons-1-machine."),
            ((13, 0), (16, 0), "Old Asia West sets", "Amritapuri/Kanpur archives."),
        ]
        if wd == 5:
            blocks.append(((17, 30), (20, 30), "AtCoder ABC", "A-D target."))
        else:
            blocks.append(((16, 30), (19, 30), "Virtual CF Div2", "2h timed."))
            blocks.append(((21, 30), (22, 0), "Weekly review + tracker update", "Ready for prelims."))
    return blocks


# ── Main ───────────────────────────────────────────────────────────
def main() -> None:
    rows: List[List[str]] = []
    d = START
    while d <= END:
        p = phase_of(d)
        wd = d.weekday()

        if wd < 5:  # Mon-Fri
            subj, desc = morning_subject(d)
            add_block(rows, d, (5, 30), (8, 0), subj, desc)
            subj, desc = evening_subject(d)
            add_block(rows, d, (16, 0), (18, 30), subj, desc)
            subj, desc = evening2_subject(d)
            add_block(rows, d, (19, 0), (21, 0), subj, desc)
            add_block(rows, d, (21, 0), (21, 30), "Review + notes",
                      "One page: new patterns, mistakes, tricks. Update templates.")
        else:  # Sat-Sun
            for start, end, subj, desc in weekend_subject(d):
                add_block(rows, d, start, end, subj, desc)

        d += timedelta(days=1)

    # Weekly Sunday review reminder (all-day, every Sunday)
    d = START
    while d <= END:
        if d.weekday() == 6:  # Sunday
            add_all_day(rows, d, "WEEKLY CHECK-IN (10 min): review + tracker update",
                        "Fill Section 11 check-in: books read, problems solved, contests, "
                        "GSoC milestone progress, rating changes, next week's 3 focus items.")
        d += timedelta(days=1)

    # Phase A weekly focus markers (all-day, Saturday)
    for i, (start, focus) in enumerate(PHASE_A_WEEKS, start=1):
        add_all_day(rows, start, f"Phase A Week {i} focus: {focus}")

    # Milestones
    for md, subj in MILESTONES:
        add_all_day(rows, md, subj)

    # Write CSV
    with open(OUT_FILE, "w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["Subject", "Start Date", "Start Time", "End Date", "End Time",
                         "All Day Event", "Description", "Location", "Private"])
        writer.writerows(rows)

    print(f"Wrote {len(rows)} events to {OUT_FILE}")
    print(f"  Phase A: {sum(1 for r in rows if 'Phase A' in r[0] or 'READING' in r[0])} events")


if __name__ == "__main__":
    main()