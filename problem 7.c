37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

#include <stdio.h>
#include <stdbool.h>

bool isValid(char board[9][9], int r, int c, char val) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[r][i] == val) return false;
        // Check column
        if (board[i][c] == val) return false;
        // Check 3x3 sub-box
        int subRow = 3 * (r / 3) + i / 3;
        int subCol = 3 * (c / 3) + i % 3;
        if (board[subRow][subCol] == val) return false;
    }
    return true;
}

bool solve(char board[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char val = '1'; val <= '9'; val++) {
                    if (isValid(board, r, c, val)) {
                        board[r][c] = val; // Try value
                        if (solve(board)) return true; // Move forward
                        board[r][c] = '.'; // Backtrack
                    }
                }
                return false; // No valid number fits
            }
        }
    }
    return true; // Board full
}

void solveSudoku(char board[9][9]) {
    solve(board);
}
