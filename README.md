# C++ Engineering Algorithms & Software Design Patterns

This repository serves as a functional gallery of algorithms, structural data patterns, and recursive problem-solving architectures implemented in modern C++. 

The projects scale from foundational mathematical logic and bitwise-style transformations to matrix operations, complex data recursion, and state-saving memory systems.

---

## 🧠 Featured Engineering Paradigms

### 1. Memory Management & Game Engine Architecture (Sudoku with Backtracking)
* **Core Concepts:** Dynamic 2D arrays (`pointer-to-pointer`), heap allocation/deallocation, state backtracking using stack-oriented arrays.
* **Implementation:** A fully decoupled console application separated into interface (`.h`) and implementation (`.cpp`) modules. Features structural verification algorithms checking $3 \times 3$ subgrid matrices and user-state history arrays to allow multi-step timeline restoration.
* **Directory:** `/04_Systems_Backtracking_Game`

### 2. Recursive Systems & Path Exploration (Dungeon Explorer)
* **Core Concepts:** High-level recursion, pass-by-reference state modification, state-machine tracking.
* **Implementation:** A text-based path-navigating engine simulating random event generation, localized orientation logging (North, East, South, West limits), runtime map drawing, and recursive terminal state checks (evaluating boundaries and zero-health conditions).
* **Directory:** `/03_Recursion_Engine/maze_dungeon_explorer.cpp`

### 3. High-Performance Math & Lookups (The Sieve of Eratosthenes)
* **Core Concepts:** Static data allocation (`std::array`), computational optimization ($O(n \log \log n)$ prime extraction).
* **Implementation:** Bypasses sequential trial division bottlenecks by utilizing twin boolean-to-integer mapping tracks to flag multi-variable arrays efficiently.
* **Directory:** `/01_Foundational_Algorithms/sieve_eratosthenes.cpp`

### 4. Matrix Operations & Data Logging (2D Workshop KPI Studio)
* **Core Concepts:** Fixed-width modern arrays (`std::array<std::array>`), multi-dimensional matrix transformation, pseudo-random operational simulation.
* **Directory:** `/02_Data_Structures_2D`

---

## 🛠️ Compilation & Environment
* **Language Standard:** C++11 / C++14 / C++17
* **Standard Libraries Standardized:** `<array>`, `<vector>`, `<algorithm>`, `<chrono>`
* **Memory Management Safety:** Zero memory leaks ensured via comprehensive heap sanitation (`delete[]` tracking on all dynamically declared double-pointers).
