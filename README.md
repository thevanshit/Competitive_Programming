## Competitive Programming

A focused collection of competitive-programming solutions, organized by platform and contest.

### Repository Structure

```text
atcoder/    AtCoder contests
codechef/   CodeChef contests and DSA challenges
codeforces/ Codeforces contests, rated problems
cses/       cses problem set
templates/  Reusable solution templates
```

### Languages and Style

- C++23 solutions compiled with GCC and Python 3.13 solutions
- Contest folders named using the official contest and problem titles
- Reusable templates for fast input/output and common utilities

### Running a Solution

Install the current Homebrew GCC release (the repository is configured for its
versioned compiler executable):

```bash
brew install gcc
g++-16 --version
```

The compiler provides GNU's `bits/stdc++.h` convenience header and supports
C++23. Verify the complete setup with:

```bash
printf '#include <bits/stdc++.h>\nint main() { return 0; }\n' >/tmp/cpp23-check.cpp
g++-16 -std=c++23 /tmp/cpp23-check.cpp -o /tmp/cpp23-check
/tmp/cpp23-check
```

Compile an individual solution with:

```bash
/opt/homebrew/bin/g++-16 -std=gnu++23 -O2 -pipe path/to/solution.cpp -o solution
./solution
```

### VS Code Setup

The repository includes a C++23 VS Code configuration in `.vscode/`:

- `C++23: build current file` (`Cmd+Shift+B`) compiles the active file with GCC.
- `C++23: run current file` builds and runs the active file in the integrated terminal.
- `Debug current C++23 file` is available from the Run and Debug panel.
- Install the recommended **Competitive Companion** and **Competitive Programming Helper** extensions. Competitive Companion sends parsed problem statements to CPH, which creates the problem files and test cases under `.cph/`.

The checked-in template is available at [`templates/solution_template.cpp`](templates/solution_template.cpp).

### Python Setup

The workspace uses Python 3.13.5 and a local `.venv` environment:

```bash
python3 -m venv .venv
source .venv/bin/activate
python --version
```

Python files can be run with the `Python 3.13: run current file` task or debugged with `Debug current Python file`. The Python extension is configured to use `.venv/bin/python`, and the `cp` snippet creates a fast-input `solve()` template. Type `cp` in a Python or C++ file and press `Tab` to insert the corresponding boilerplate.

### Public Profile

Public profiles for [`thevanshit`](https://github.com/thevanshit):

- [AtCoder](https://atcoder.jp/users/thevanshit)
- [CodeChef](https://www.codechef.com/users/thevanshit)
- [Codeforces](https://codeforces.com/profile/thevanshitgaur)
- [LeetCode](https://leetcode.com/u/thevanshit/)


### No More contribution to this repo after this i'll be solving problems differently a major setback hit and gonna change everything after it - dated (25 Oct 2026).