#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(int row, int col, const vector<int>& board) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i] == col) {
            return false;
        }
    }

    // Check if there is a queen in the same diagonal (left-upper to right-lower)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i] == j) {
            return false;
        }
    }

    // Check if there is a queen in the same diagonal (right-upper to left-lower)
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
        if (board[i] == j) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using branch and bound backtracking
bool solveNQueensUtil(int row, vector<int>& board, vector<vector<int>>& solutions) {
    int n = board.size();

    // If all queens are placed, a solution is found
    if (row == n) {
        solutions.push_back(board);
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board)) {
            // Place the queen at the current position
            board[row] = col;

            // Recursively solve for the next row
            if (solveNQueensUtil(row + 1, board, solutions)) {
                foundSolution = true;
            }

            // Backtrack and remove the queen from the current position
            board[row] = -1;
        }
    }

    return foundSolution;
}

// Function to solve the N-Queens problem and print the solutions
void solveNQueens(int n) {
    vector<int> board(n, -1);  // Initialize the board with no queens placed
    vector<vector<int>> solutions;

    // Solve the N-Queens problem
    solveNQueensUtil(0, board, solutions);

    // Print the solutions
    int numSolutions = solutions.size();
    if (numSolutions > 0) {
        cout << "Found " << numSolutions << " solution(s) for N = " << n << ":\n\n";
        for (const vector<int>& solution : solutions) {
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < n; ++col) {
                    if (solution[row] == col) {
                        cout << "Q ";
                    } else {
                        cout << ". ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }
    } else {
        cout << "No solutions found for N = " << n << ".\n";
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
