

## ♛ N-Queens Problem Solver | Java

A recursive backtracking solution to the classic N-Queens challenge, placing N queens on an N×N board such that no two threaten each other.

[![Java](https://img.shields.io/badge/Language-Java-orange.svg)](https://www.java.com)
[![View Repository](https://img.shields.io/badge/GitHub-Repository-blue?logo=github)](https://github.com/your-username/n-queens-java)

### Key Features
- ✔️ Complete enumeration of all valid configurations  
- ✔️ Efficient conflict detection for columns and diagonals  
- ✔️ Optimized recursion with early pruning  
- ✔️ Clean ASCII-based board visualization  

### Technical Details
- **Time Complexity**: O(N!) worst-case  
- **Space Complexity**: O(N) stack and position tracking  
- **Input Constraint**: 1 ≤ N ≤ 9  

> 🔍 Explore code and examples [here](https://github.com/your-username/n-queens-java)

---

## 🔁 Circular Dependency Detector | C++

A C++ utility to detect circular dependencies in modular systems using graph cycle detection algorithms.

[![C++](https://img.shields.io/badge/Language-C%2B%2B-lightgrey.svg)](https://isocpp.org)
[![View Repository](https://img.shields.io/badge/GitHub-Repository-blue?logo=github)](https://github.com/your-username/circular-dependency-cpp)

### Algorithms Implemented
- **DFS (Three-Color Marking)**  
- **Kahn’s Topological Sort Algorithm**

### Capabilities
- ✔️ Detects self-loops and complex cycles  
- ✔️ Supports disconnected components  
- ✔️ Efficient O(V + E) runtime  
- ✔️ Includes comprehensive test cases  

### Function Signature
```cpp
bool hasCircularDependency(int n, vector<vector<int>>& edges);
