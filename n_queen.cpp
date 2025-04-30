// #include <iostream>
// #include <vector>
// using namespace std;

// void printBoard(const vector<int>& board, int n) {
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j)
//             cout << (board[i] == j ? "Q " : ". ");
//         cout << endl;
//     }
//     cout << endl;
// }

// void solveNQueensUtil(int row, int n, vector<int>& board,
//                       vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
//                       int& solutions) {
//     if (row == n) {
//         solutions++;
//         printBoard(board, n);
//         return;
//     }

//     for (int col = 0; col < n; ++col) {
//         if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col]) {
//             board[row] = col;
//             cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

//             solveNQueensUtil(row + 1, n, board, cols, diag1, diag2, solutions);

//             cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
//         }
//     }
// }

// void solveNQueens(int n) {
//     vector<int> board(n, -1);                  // board[i] = column of queen in row i
//     vector<bool> cols(n, false);               // is column occupied
//     vector<bool> diag1(2 * n - 1, false);      // main diagonals
//     vector<bool> diag2(2 * n - 1, false);      // anti-diagonals
//     int solutions = 0;

//     solveNQueensUtil(0, n, board, cols, diag1, diag2, solutions);

//     cout << "Total solutions: " << solutions << endl;
// }

// int main() {
//     int n;
//     cout << "Enter number of queens (N): ";
//     cin >> n;

//     solveNQueens(n);

//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }
};
int main() {
  int n = 8; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}