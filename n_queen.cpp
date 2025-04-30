#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<int>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (board[i] == j ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

void solveNQueensUtil(int row, int n, vector<int>& board,
                      vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                      int& solutions) {
    if (row == n) {
        solutions++;
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
            board[row] = col;
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            solveNQueensUtil(row + 1, n, board, cols, diag1, diag2, solutions);

            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
}

void solveNQueens(int n) {
    vector<int> board(n, -1);                  // board[i] = column of queen in row i
    vector<bool> cols(n, false);               // is column occupied
    vector<bool> diag1(2 * n - 1, false);      // main diagonals
    vector<bool> diag2(2 * n - 1, false);      // anti-diagonals
    int solutions = 0;

    solveNQueensUtil(0, n, board, cols, diag1, diag2, solutions);

    cout << "Total solutions: " << solutions << endl;
}

int main() {
    int n;
    cout << "Enter number of queens (N): ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
