# Algos
My own saved solutions to algorithmic problems

## Folder Structure

This repository is organized into the following categories:

- **[dynamic-programming](./dynamic-programming)** — Dynamic programming problems and techniques (memoization, tabulation, LCS, subset partition, subsequence queries)
- **[graph-algorithms](./graph-algorithms)** — Graph problems: DFS, topological sort, Dijkstra, path finding, prefix/suffix influence
- **[tree-algorithms](./tree-algorithms)** — Tree problems: subtree size accumulation, tree DP with subtree products
- **[greedy-and-data-structures](./greedy-and-data-structures)** — Greedy algorithms and data structures: segment trees, monotonic stack, quicksort, Tower of Hanoi, priority-queue matching
- **[systems-architecture](./systems-architecture)** — Low-level systems: x86-64 GShare branch predictor in assembly with a C++ driver

Each folder contains a README with descriptions of every program it contains.

## Why this matters for ML

Algorithmic thinking translates directly into better ML engineering:

- **Complexity intuition** — DP, graph search, and segment trees train you to reason about time and space trade-offs, which is essential when profiling and optimising ML pipelines.
- **Efficient data processing** — Data structures like priority queues, monotonic stacks, and range-query trees map naturally onto fast preprocessing pipelines, negative-sampling strategies, and approximate nearest-neighbour search in production systems.
- **Low-level performance** — The branch-predictor project builds hands-on understanding of CPU behaviour and memory access patterns, which matters when squeezing throughput out of training loops or inference code.

This background helps me implement efficient preprocessing pipelines that don't become bottlenecks, build effective negative sampling for large-scale retrieval models, and choose data structures with the hardware impact in mind.

## LeetCode Problems

LeetCode solutions are organised in the **[LeetCode](./LeetCode)** folder, with the following topic subfolders:

- **[LeetCode/Arrays-and-Strings](./LeetCode/Arrays-and-Strings)** — Array and string manipulation
- **[LeetCode/Trees-and-Graphs](./LeetCode/Trees-and-Graphs)** — Tree and graph data structures
- **[LeetCode/Dynamic-Programming](./LeetCode/Dynamic-Programming)** — Dynamic programming
- **[LeetCode/Sorting-and-Searching](./LeetCode/Sorting-and-Searching)** — Sorting and searching
- **[LeetCode/Math-and-Logic](./LeetCode/Math-and-Logic)** — Mathematical and logical problems
- **[LeetCode/Linked-Lists](./LeetCode/Linked-Lists)** — Linked list problems
- **[LeetCode/Backtracking](./LeetCode/Backtracking)** — Backtracking and recursion
- **[LeetCode/Two-Pointers](./LeetCode/Two-Pointers)** — Two-pointer technique problems
