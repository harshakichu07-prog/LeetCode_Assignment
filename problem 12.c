52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

#include <stdio.h>
#include <stdbool.h>

void solve(int r, int n, bool c[], bool d1[], bool d2[], int* count) {
    if (r == n) {
        (*count)++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (c[j] || d1[r + j] || d2[r - j + n - 1]) continue;

        c[j] = d1[r + j] = d2[r - j + n - 1] = true;
        solve(r + 1, n, c, d1, d2, count);
        c[j] = d1[r + j] = d2[r - j + n - 1] = false;
    }
}

int totalNQueens(int n) {
    int count = 0;
    bool c[20] = {0}, d1[40] = {0}, d2[40] = {0};
    solve(0, n, c, d1, d2, &count);
    return count;
}

int main() {
    int n = 4;
    printf("%d", totalNQueens(n));
    return 0;
}
