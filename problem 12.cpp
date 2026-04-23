52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false), diag1(2*n-1, false), diag2(2*n-1, false);
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row+col] || diag2[row-col+n-1]) continue;
            cols[col] = diag1[row+col] = diag2[row-col+n-1] = true;
            backtrack(row+1, n, cols, diag1, diag2, count);
            cols[col] = diag1[row+col] = diag2[row-col+n-1] = false;
        }
    }
};
