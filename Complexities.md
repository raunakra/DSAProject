# DSA Complexity Reference

Quick reference listing common data structures and algorithms with time & space complexities.

How to use
- This is a concise lookup to help pick the right data structure / algorithm for a problem.
- Where appropriate the reference points to example files already in this repo.

## Data structures (operations = Access / Search / Insert / Delete / Extra Space)

| Structure | Access | Search | Insert | Delete | Space |
|---|---:|---:|---:|---:|---:|
| Array / static | O(1) | O(n) | O(n) | O(n) | O(n) |
| Dynamic Array (vector) | O(1) amortized | O(n) | O(1) amortized | O(n) | O(n) |
| Singly Linked List | O(n) | O(n) | O(1) (head) | O(1) (head) | O(n) |
| Doubly Linked List | O(n) | O(n) | O(1) | O(1) | O(n) |
| Stack (LIFO) | O(n) | O(n) | O(1) | O(1) | O(n) |
| Queue (FIFO) | O(n) | O(n) | O(1) | O(1) | O(n) |
| Deque | O(n) | O(n) | O(1) | O(1) | O(n) |
| Hash table (unordered_map) | O(1) average | O(1) average | O(1) average | O(1) average | O(n) |
| Binary Search Tree (unbalanced) | O(n) worst / O(log n) avg | O(n) worst / O(log n) avg | O(n) / O(log n) | O(n) / O(log n) | O(n) |
| Balanced BST (AVL / RB-tree) | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |
| Binary Heap (priority_queue) | O(n) | O(n) | O(log n) | O(log n) | O(n) |
| Trie (prefix tree) | O(L) | O(L) | O(L) | O(L) | O(ALPHABET * nodes) |
| Disjoint Set (Union-Find, with path compression + union by rank) | O(α(n)) amortized | O(α(n)) | O(α(n)) | O(α(n)) | O(n) |
| Graph (adjacency list) | O(1) per neighbor | O(V+E) for traversals | O(1) per edge | O(1) per edge | O(V+E) |
| Graph (adjacency matrix) | O(1) | O(V^2) | O(1) | O(1) | O(V^2) |

## Common algorithms

### Sorting
| Algorithm | Best | Average | Worst | Extra Space |
|---|---:|---:|---:|---:|
| Bubble / Insertion / Selection | O(n) (insertion best) | O(n^2) | O(n^2) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n^2) | O(log n) average stack |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |

Examples: see sorting patterns across the repo — use `Standard_BS.cpp` or other comparator-based utilities for reference.

### Search & Selection
- Binary search: O(log n) time, O(1) space. Example: `9. Binary_Search/Standard_BS.cpp`.
- Quick-select (kth element): Average O(n), worst O(n^2); O(1) additional space.

### Heaps & Priority problems
- Build heap: O(n) (bottom-up), push/pop: O(log n). Useful for Top-K problems — see `6. Heaps_Priority_Queue/Top_K.cpp` and `Merge_K_Sorted.cpp`.

### Graph algorithms
- BFS / DFS: O(V+E) time, O(V) extra space (queue/stack + visited). Example: `7. Graphs/BFS_DFS.cpp`.
	- Rotting oranges (grid / multi-source BFS): O(R * C) time, O(R * C) space. Example: `7. Graphs/Rotten_Oranges.cpp`.
	- Word ladder (pattern BFS): O(N * L) time to build patterns + O(N * L) overall BFS, Space: O(N * L). Example: `7. Graphs/Word_Ladder.cpp`.
- Dijkstra (binary heap): O((V+E) log V) typical, O(V) space. See `7. Graphs/Dijkstra.cpp`.
- Topological sort: O(V+E) time, O(V) space. See `7. Graphs/Topological_Sort.cpp`.
- Kruskal (using union-find): O(E log E) with union-find for connectivity; see `7. Graphs/MST_Kruskal.cpp`.

### Dynamic Programming (DP)
- Typical DP table (1D): O(n) time per subproblem; 2D-table: O(n*m) time and O(n*m) space.
- Many DP problems can be optimized to O(1) or O(n) space by reusing rows/columns — examine `8. Dynamic_Programming/1D_DP.cpp` and `2D_DP.cpp`.

### Backtracking / Exhaustive search
- Subsets / Permutations: O(n * n!) (permutation generation) time and O(n) - O(n!) depending on output. See `10. Backtracking/N_Queens.cpp` and `Subsets_Permutations.cpp`.

### String & Two-pointer techniques
- Two-pointer sliding-window (variable): typically O(n) time, O(1) extra space. See `1. Arrays_Strings/Sliding_Window.cpp`.

### Bit manipulation
- Bit tricks: O(1) per operation; used for constant-time checks (popcount, shift). See `11. Bit_Manipulation/Tricks.cpp`.

---

If you'd like this reference expanded (more algorithms, code snippets, visual examples, or a CSV export), tell me which areas you want prioritized and I'll extend this file.
