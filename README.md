# DSAProject — Data Structures & Algorithms Repository

A comprehensive collection of **standalone C++ implementations** for common data structures and algorithms, organized by topic and optimized for interview preparation. Perfect for Amazon, Salesforce, and other FAANG companies.

[**📖 View Full Documentation**](https://raunakra.github.io/DSAProject) | [**📋 Browse Topics**](TOPICS.md) | [**📚 Algorithm Index**](list.md)

---

## 🎯 Overview

This repository contains **production-ready C++17 implementations** of essential algorithms and data structures. Each example is:

- ✅ **Fully compilable** — No external dependencies, single-file examples
- ✅ **Well-documented** — Problem statements, complexity analysis, and test cases
- ✅ **Company-focused** — Curated problems from Amazon & Salesforce interviews
- ✅ **Interview-ready** — Optimized solutions with clean, idiomatic C++

---

## 🗂️ Repository Structure

```
1. Arrays_Strings/           → Two pointers, sliding window, prefix sum
2. Linked_Lists/             → Reversal, cycle detection, dummy nodes
3. Stacks_Queues/            → Monotonic stacks, expression evaluation, deques
4. Trees/                    → Traversals, LCA, tree properties, binary trees
5. Binary_Search_Trees/      → BST operations, successor/predecessor
6. Heaps_Priority_Queue/     → Top K, merge K lists, median finder
7. Graphs/                   → BFS/DFS, cycle detection, shortest paths
8. Dynamic_Programming/      → 1D/2D DP, tree DP, knapsack variations
9. Binary_Search/            → Standard, rotated arrays, answer space search
10. Backtracking/            → Subsets, permutations, N-Queens, Sudoku
11. Bit_Manipulation/        → Single number, hamming weight, XOR tricks
REFERENCE/                   → Big-O complexities cheat sheet
```

---

## 📁 Key Files

| File | Purpose |
|------|---------|
| [**TOPICS.md**](TOPICS.md) | Complete file listing with complexity annotations |
| [**list.md**](list.md) | Conceptual hierarchy of topics |
| [**Complexities.md**](REFERENCE/Complexities.md) | Quick reference: Time/Space complexities |

---

## 🚀 Quick Start

### Compile & Run Any Example

```bash
# Windows (PowerShell)
g++ -std=c++17 "1. Arrays_Strings/Two_Pointers.cpp" -O2 -o example.exe
.\example.exe

# Linux/macOS
g++ -std=c++17 "1. Arrays_Strings/Two_Pointers.cpp" -O2 -o example
./example
```

### Example Files by Category

#### **Arrays & Strings**
- `Two_Pointers.cpp` — Container with most water, trapping rain water
- `Sliding_Window.cpp` — Longest substring without repeating, min window substring
- `Prefix_Sum.cpp` — Range sum queries, subarray problems
- `Amazon_Salesforce_Questions.cpp` — **7 frequently asked interview problems**

#### **Linked Lists**
- `Fast_Slow_Pointers.cpp` — Cycle detection, find middle node
- `Reversal.cpp` — Reverse k-group, palindrome checks
- `Amazon_Salesforce_Questions.cpp` — **5 interview problems**

#### **Trees**
- `Traversals.cpp` — All tree traversal patterns (inorder, level-order, etc.)
- `LCA.cpp` — Lowest common ancestor (recursive & iterative)
- `Amazon_Salesforce_Questions.cpp` — **6 interview problems**

#### **Graphs**
- `BFS_DFS.cpp` — Connected components, pathfinding
- `Dijkstra.cpp` — Shortest path in weighted graphs
- `Kosaraju_SCC.cpp` — Strongly connected components
- `Amazon_Salesforce_Questions.cpp` — **5 interview problems**

#### **Dynamic Programming**
- `1D_DP.cpp` — Climbing stairs, house robber, unbounded knapsack
- `2D_DP.cpp` — Grid problems, longest common subsequence
- `Amazon_Salesforce_Questions.cpp` — **15 interview problems**

#### **Binary Search**
- `Standard_BS.cpp` — Classic binary search
- `Rotated_Array.cpp` — Search in rotated sorted array
- `Amazon_Salesforce_Questions.cpp` — **13 interview problems**

#### **Backtracking**
- `Subsets_Permutations.cpp` — Generate subsets and permutations
- `Palindrome_Partitioning.cpp` — Partition into palindromes
- `Amazon_Salesforce_Questions.cpp` — **11 interview problems**

#### **Bit Manipulation**
- `Single_Number.cpp` — XOR-based solutions
- `Basic_Operations.cpp` — Bit shifts, masks, tricks
- `Amazon_Salesforce_Questions.cpp` — **17 interview problems**

#### **Heaps & Priority Queues**
- `Top_K.cpp` — K-th largest, top K frequent
- `Merge_K_Sorted.cpp` — Merge sorted lists/arrays
- `Amazon_Salesforce_Questions.cpp` — **12 interview problems**

---

## 📊 Company-Specific Questions

Each topic folder includes `Amazon_Salesforce_Questions.cpp` with frequently asked interview problems:

- **Arrays/Strings**: 7 problems
- **Linked Lists**: 5 problems
- **Stacks/Queues**: 5 problems
- **Trees**: 6 problems
- **BST**: 13 problems
- **Heaps**: 12 problems
- **Graphs**: 5 problems
- **DP**: 15 problems
- **Binary Search**: 13 problems
- **Backtracking**: 11 problems
- **Bit Manipulation**: 17 problems

**Total: 110+ frequently asked interview problems**

---

## 🔍 How to Use This Repository

### For Interview Prep
1. Pick a topic from [**list.md**](list.md)
2. Study the conceptual patterns in the folder
3. Solve the `Amazon_Salesforce_Questions.cpp` problems
4. Check [**Complexities.md**](REFERENCE/Complexities.md) for Big-O analysis
5. Run locally and test edge cases

### For Learning
1. Start with basic patterns (Two Pointers, Sliding Window)
2. Progress to complex patterns (DP on Trees, Graph Algorithms)
3. Use [**TOPICS.md**](TOPICS.md) to explore all implementations
4. Reference complexity cheat sheet for optimization insights

### For Implementation Reference
- Look up similar problems in [**TOPICS.md**](TOPICS.md)
- Copy pattern and adapt for your problem
- Verify complexity in [**Complexities.md**](REFERENCE/Complexities.md)

---

## 💡 Key Patterns & Algorithms

### Essential Patterns
- ✅ Two Pointers (opposite direction, same direction)
- ✅ Sliding Window (fixed & variable size)
- ✅ Binary Search (standard, rotated arrays, answer space)
- ✅ BFS/DFS (connected components, pathfinding)
- ✅ Dynamic Programming (1D, 2D, tree DP)
- ✅ Backtracking (subsets, permutations, combinations)
- ✅ Bit Manipulation (XOR tricks, hamming weight)

### Advanced Topics
- ✅ Dijkstra's Algorithm (shortest paths)
- ✅ Kosaraju SCC (strongly connected components)
- ✅ Union-Find (disjoint set union)
- ✅ Kruskal's MST (minimum spanning trees)
- ✅ Morris Traversal (O(1) space tree traversal)
- ✅ Segment Trees (range queries)

---

## 📈 Complexity Reference

Quick Big-O lookup for common algorithms:

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Binary Search | O(log n) | O(log n) | O(log n) | O(1) |
| Hash Table | O(1) | O(1) | O(n) | O(n) |
| Binary Search Tree | O(log n) | O(log n) | O(n) | O(log n) |
| Dijkstra | — | O((V+E) log V) | — | O(V) |
| BFS/DFS | — | O(V+E) | — | O(V) |

See [**Complexities.md**](REFERENCE/Complexities.md) for full reference.

---

## 🛠️ Build & Compile

### Requirements
- **C++17** or higher
- **g++** or **clang++** compiler
- No external dependencies

### Compilation Examples

```bash
# Single file compile (most common)
g++ -std=c++17 "topic/file.cpp" -O2 -o output

# With all optimizations
g++ -std=c++17 "topic/file.cpp" -O3 -march=native -o output

# With warnings
g++ -std=c++17 -Wall -Wextra "topic/file.cpp" -O2 -o output
```

---

## 📝 File Format

Each `.cpp` file follows this structure:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Problem description and complexity analysis

// Helper functions and implementations

int main() {
    // Example test cases
    cout << "Test case result: " << solution(...) << "\n";
    return 0;
}
```

---

## 🌐 GitHub Pages

This repository is hosted on GitHub Pages at:  
**[raunakra.github.io/DSAProject](https://raunakra.github.io/DSAProject)**

### How It Works
- Markdown files (`.md`) are automatically rendered as HTML
- Navigate using links in [**TOPICS.md**](TOPICS.md) and [**list.md**](list.md)
- Code files display with syntax highlighting
- Mobile-friendly responsive design

---

## 🤝 Contributing

Found a bug? Want to add a solution? Contributions welcome!

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/add-new-algorithm`)
3. Commit changes (`git commit -am 'Add new algorithm'`)
4. Push to branch (`git push origin feature/add-new-algorithm`)
5. Open a Pull Request

### Guidelines
- Keep solutions minimal and self-contained
- Include complexity analysis in comments
- Add test cases in `main()`
- Follow existing file naming conventions
- Update [TOPICS.md](TOPICS.md) and [list.md](list.md)

---

## 📚 Learning Resources

### Recommended Topics by Interview Stage

**Initial Prep**
- Arrays & Strings (Two Pointers, Sliding Window)
- Linked Lists (Fast/Slow Pointers)
- Stacks & Queues

**Intermediate**
- Trees (All traversals, LCA, Properties)
- Binary Search
- Dynamic Programming (1D, 2D)

**Advanced**
- Graphs (BFS, DFS, Dijkstra, SCC)
- Backtracking
- Bit Manipulation
- Advanced DP

---

## 📄 License

This repository is open source and available under the [MIT License](LICENSE).

---

## ⭐ Show Your Support

If this repository helped you in your interview preparation, please consider:
- ⭐ **Star** this repository
- 🍴 **Fork** it for your own reference
- 📢 **Share** with friends preparing for interviews
- 💬 **Discuss** solutions in the community

---

## 📧 Contact & Support

For questions, suggestions, or corrections:
- Open an [Issue](https://github.com/raunakra/DSAProject/issues)
- Reach out via [GitHub Discussions](https://github.com/raunakra/DSAProject/discussions)

---

**Last Updated:** December 28, 2025  
**Total Problems:** 110+ interview questions from Amazon & Salesforce  
**Languages:** C++17  
**Status:** ✅ Actively Maintained

Happy coding! 🚀
