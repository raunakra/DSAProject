Project snapshot
- Purpose: repository of standalone C++ algorithm / DS solutions organized by topic.
- Top-level index: `list.md` describes folders (e.g. `6. Heaps_Priority_Queue`).

How this repo is organized
- One folder per topic (prefixed by number + short name). Example: `6. Heaps_Priority_Queue`.
- Each folder contains self-contained `.cpp` examples implementing a single algorithm or problem.
- Files are typically compilable standalone and include a small `main()` that demonstrates or prints results (e.g. `Merge_K_Sorted.cpp`).

What matters when editing or adding code
- Keep new solutions as single `.cpp` files that compile without external dependencies.
- Follow file naming and placement: put new solutions in the topic folder that best matches the problem and name the file descriptively (CamelCase or underscores are already used: e.g. `Two_Pointers.cpp`, `Running_Median.cpp`).
- Keep examples short and self-contained: include a `main()` with sample input/output so reviewers can compile & run it quickly.

Build / run (developer workflow)
- No build system in repo — compile single-file examples locally.
- On Windows (PowerShell) with g++ (MinGW / MSYS):
  - g++ -std=c++17 "path\to\src.cpp" -O2 -o "path\to\out.exe"; .\path\to\out.exe
  - Example: `g++ -std=c++17 "6. Heaps_Priority_Queue/Merge_K_Sorted.cpp" -O2 -o Merge_K_Sorted.exe; .\Merge_K_Sorted.exe`
- On Linux/macOS: `g++ -std=c++17 file.cpp -O2 -o out && ./out`

Project conventions and style (for AI agents)
- Prefer the existing minimal, imperative style used across files: `#include` standard libraries, `using namespace std;`, small helper structs/functions, and an example `main()`.
- Avoid adding broad cross-cutting changes (global headers, central test harness) unless you update `list.md` and document the change — the repository is intentionally minimal.
- Keep changes localized to the problem file and the `list.md` index when adding or removing topics.

Patterns and notable files
- `list.md` — canonical topic index; update it when adding new topic folders or problems.
- Examples: `6. Heaps_Priority_Queue/Merge_K_Sorted.cpp` shows a common pattern: small helper struct (`ListNode`), a standalone `mergeKLists` function, and a `main()` that prints a short message.

If you need to do more
- Add small helper tests as an inline `main()`; if the change grows beyond an example, propose a simple build/test harness in an issue first.

Questions or missing details
- If anything in this guidance is unclear, ask for screenshots or a particular file to examine; maintainers prefer minimal, easily-compilable files.

Keep the guidance short and focused — this file aims to help agents be immediately productive in this repo.
