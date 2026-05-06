# Competitive Programming

A structured collection of **Data Structures & Algorithms (DSA)** and **Competitive Programming (CP)** solutions implemented in **C++**.
This repository is intended for practice, revision, and long-term reference while preparing for interviews and programming contests.

## Repository Structure

```
Competitive_Programming/
├── codeforces/
│   ├── contests/          # Round-by-round contest solutions
│   │   ├── round-1077-div2/
│   │   ├── round-1078-div2/
│   │   └── ...
│   └── rated/             # Problems organized by difficulty rating
│       ├── 900-1000/
│       ├── 1000-1100/
│       └── 1100-1200/
├── codechef/
│   └── contests/          # CodeChef Starters contest solutions
│       ├── START223/
│       ├── START225/
│       └── ...
├── atcoder/
│   └── contests/          # AtCoder Beginner Contest solutions
│       ├── abc-443/
│       ├── abc-445/
│       └── ...
├── cses/                  # CSES Problem Set solutions
│   ├── introductory/
│   └── CP HandBook.pdf
├── .cph/                  # CPH extension config (do not delete)
├── .gitignore
└── README.md
```

## Purpose

- Practice fundamental and advanced DSA concepts
- Store competitive programming solutions in an organized manner
- Build reusable problem-solving patterns
- Serve as a personal reference for revision and interviews

## Language & Tools

- **Language:** C++
- **Standard:** C++17 (recommended)
- **IDE:** VS Code with CPH (Competitive Programming Helper) extension

## Usage

Clone the repository:

```bash
git clone https://github.com/thevanshit/Competitive_Programming.git
cd Competitive_Programming
```

Compile and run any solution:

```bash
g++ -std=c++17 file.cpp
./a.out
```

## Platforms Covered

| Platform | Location | Format |
|----------|----------|--------|
| CodeForces | `codeforces/contests/` | Round solutions (A, B, C, D...) |
| CodeForces | `codeforces/rated/` | Problems by difficulty rating |
| CodeChef | `codechef/contests/` | START series contests |
| AtCoder | `atcoder/contests/` | ABC (Beginner Contest) |
| CSES | `cses/` | Problem Set (Introductory, etc.) |

## Naming Convention

All solution files follow the pattern:

```
<ProblemLetter>_<Problem_Title_In_Snake_Case>.cpp
```

Example: `A_Friendly_Numbers.cpp`, `B_Split_Ticketing.cpp`

## Contribution Guidelines

Contributions are welcome. To contribute:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/your-feature`)
3. Add clean, well-documented solutions
4. Submit a pull request

Please follow consistent naming conventions and write readable code with comments where the logic is non-trivial.

## License

This repository is open for learning and personal use.
