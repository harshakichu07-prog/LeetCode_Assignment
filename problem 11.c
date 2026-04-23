51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void solve(int r, int n, char board[n][n], bool c[n], bool d1[2*n], bool d2[2*n]) {
    if (r == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) printf("%c ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int j = 0; j < n; j++) {
        if (c[j] || d1[r + j] || d2[r - j + n - 1]) continue;

        board[r][j] = 'Q';
        c[j] = d1[r + j] = d2[r - j + n - 1] = true;

        solve(r + 1, n, board, c, d1, d2);

        board[r][j] = '.';
        c[j] = d1[r + j] = d2[r - j + n - 1] = false;
    }
}

int main() {
    int n = 4;
    char board[n][n];
    bool c[10] = {0}, d1[20] = {0}, d2[20] = {0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) board[i][j] = '.';

    solve(0, n, board, c, d1, d2);
    return 0;
}
