#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
        
    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
        
    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
        
    return true;
}

void solveNQueensUtil(int row, int n, vector<string>& board, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensUtil(row + 1, n, board, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solveNQueensUtil(0, n, board, result);
    return result;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);
    cout << "Number of solutions for " << n << "-Queens: " << solutions.size() << endl;
    return 0;
}
