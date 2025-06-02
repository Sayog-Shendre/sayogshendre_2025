N-Queens Problem Solution
A Java implementation of the classic N-Queens puzzle using a backtracking algorithm.

Problem Description
The N-Queens puzzle challenges us to place N chess queens on an N×N chessboard so that no two queens attack each other. This implies three critical conditions:

No two queens can be in the same row.

No two queens can be in the same column.

No two queens can be on the same diagonal.

Solution Approach
This implementation leverages backtracking with several key optimizations:

Row-by-row placement: Queens are placed one per row, inherently resolving row conflicts.

Column tracking: An array is used to efficiently track column positions.

Diagonal validation: Both main and anti-diagonals are checked using simple mathematical relationships.

Early pruning: The algorithm backtracks immediately upon detecting any conflicts, significantly reducing the search space.

Algorithm Complexity
Time Complexity: O(N!) in the worst case, but significantly better in practice due to effective pruning.

Space Complexity: O(N) for the recursion stack and position tracking array.

Code Structure
The core logic is encapsulated within the Main class:

public class Main {
    // Main solution method to initiate the N-Queens problem solving
    public List<List<String>> solveNQueens(int n)

    // Backtracking recursive function to explore possible queen placements
    private void backtrack(List<List<String>> result, int[] queens, int row, int n)

    // Conflict detection: checks if placing a queen at (row, col) is valid
    private boolean isValid(int[] queens, int row, int col)

    // Converts the internal solution format to the required chessboard representation
    private List<String> generateBoard(int[] queens, int n)
}

Examples
Example 1: N=4
Input: n = 4

Output:

Solution 1:
.Q..
...Q
Q...
..Q.

Solution 2:
..Q.
Q...
...Q
.Q..

Example 2: N=1
Input: n = 1

Output:

Q

How to Run
Compile the Java file:

javac Main.java

Run the program:

java Main

Expected Output:

N = 4:
Solution 1:
.Q..
...Q
Q...
..Q.
Solution 2:
..Q.
Q...
...Q
.Q..

N = 1:
Q

N = 8 has 92 solutions

Key Features
✅ Complete Solutions: Finds all possible valid arrangements of queens.

✅ Efficient Backtracking: Prunes invalid paths early for optimized performance.

✅ Scalable: Works for various values of N (tested up to N=9).

✅ Clean Output: Formats solutions into readable chessboard representations.

✅ Multiple Test Cases: Includes examples for N=1, N=4, and N=8.

Implementation Details
Data Structure
The solution uses an int[] queens array, where queens[i] = j signifies that the queen in row i is placed in column j. This representation inherently eliminates row conflicts.

Conflict Detection
Conflict detection is crucial for the backtracking algorithm. It primarily checks for column and diagonal conflicts:

// Column conflict: same column
if (prevCol == col) return false;

// Diagonal conflict: slope = ±1 (checking both main and anti-diagonals)
if (Math.abs(i - row) == Math.abs(prevCol - col)) return false;

Board Generation
After finding a valid queens array, it's converted into a List<String> format, where 'Q' represents a queen and '.' represents an empty space on the board.

Constraints
1≤n≤9 (as per typical problem requirements)

The solution returns all distinct valid arrangements.

Solutions can be returned in any order.

Performance
N

Solutions

Time Complexity

1

1

O(1)

4

2

O(4!)

8

92

O(8!)

9

352

O(9!)

Contributing
Feel free to submit issues and enhancement requests! Your contributions are welcome.

License
This project is open source and available under the MIT License.
