N-Queens Problem Solution
A Java implementation of the classic N-Queens puzzle using backtracking algorithm.
Problem Description
The N-Queens puzzle is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. This means:

No two queens can be in the same row
No two queens can be in the same column
No two queens can be on the same diagonal

Solution Approach
This implementation uses backtracking with the following optimizations:

Row-by-row placement: Place one queen per row to eliminate row conflicts
Column tracking: Use array indexing to track column positions
Diagonal validation: Check both diagonal directions using mathematical relationships
Early pruning: Backtrack immediately when conflicts are detected

Algorithm Complexity

Time Complexity: O(N!) in worst case, but significantly better in practice due to pruning
Space Complexity: O(N) for recursion stack and position tracking

Code Structure
javapublic class Main {
    // Main solution method
    public List<List<String>> solveNQueens(int n)
    
    // Backtracking recursive function
    private void backtrack(List<List<String>> result, int[] queens, int row, int n)
    
    // Conflict detection
    private boolean isValid(int[] queens, int row, int col)
    
    // Convert solution to required format
    private List<String> generateBoard(int[] queens, int n)
}
Examples
Example 1: N = 4
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
Example 2: N = 1
Input: n = 1
Output:
Q
How to Run

Compile the Java file:
bashjavac Main.java

Run the program:
bashjava Main

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

✅ Complete Solutions: Finds all possible valid arrangements
✅ Efficient Backtracking: Prunes invalid paths early
✅ Scalable: Works for any N (tested up to N=9)
✅ Clean Output: Formats solutions as required chess board representation
✅ Multiple Test Cases: Includes examples for N=1, N=4, and N=8

Implementation Details
Data Structure

Uses int[] queens where queens[i] = j means queen in row i is at column j
This representation automatically eliminates row conflicts

Conflict Detection
java// Column conflict: same column
if (prevCol == col) return false;

// Diagonal conflict: slope = ±1
if (Math.abs(i - row) == Math.abs(prevCol - col)) return false;
Board Generation
Converts the internal integer array representation to the required string format with 'Q' for queens and '.' for empty spaces.
Constraints

1 ≤ n ≤ 9 (as per problem requirements)
Returns all distinct solutions
Solutions can be returned in any order

Performance
NSolutionsTime Complexity11O(1)42O(4!)892O(8!)9352O(9!)
Contributing
Feel free to submit issues and enhancement requests!
License
This project is open source and available under the MIT License.
