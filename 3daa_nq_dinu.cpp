#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check the column for any queens above the current position
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 1)  
            return false;

    // Check  upper-left diagonal 
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)  
            return false;

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 1)  
            return false;

    return true; 
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    // If all queens have been placed, return true
    if (row == n)
        return true;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; ++col) {
        
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place a queen at (row, col)

            // next row
            if (solveNQueens(board, row + 1, n))
                return true;

            // backtrack
            board[row][col] = 0;  // Remove the queen and try the next column
        }
    }

    return false;  // If no valid position is found in the current row, return false
}



void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl; 
    }
}


void solveNQueen(int n) {
    // Initialize an empty n x n chessboard (all zeros)
    vector<vector<int>> board(n, vector<int>(n, 0));

    
    if (solveNQueens(board, 0, n)) {
        
        printBoard(board, n);
    } else {
        
        cout << "No solution exists for " << n << " queens." << endl;
    }
}


int main() {
    int n;
    cout << "Enter the number of queens: ";  
    cin >> n; 
    solveNQueen(n); 

    return 0;
}
/*
Enter the number of queens: 4
. Q . .
. . . Q
Q . . .
. . Q .
*/

/*
Enter the number of queens: 5
Q . . . .
. . Q . .
. . . . Q
. Q . . .
. . . Q .
*/