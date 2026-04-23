85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

#include <stdio.h>
#include <stdlib.h>

int largestHist(int* h, int n) {
    int* st = (int*)malloc((n + 1) * sizeof(int));
    int top = -1, maxA = 0;
    for (int i = 0; i <= n; i++) {
        int curH = (i == n ? 0 : h[i]);
        while (top != -1 && curH < h[st[top]]) {
            int height = h[st[top--]];
            int width = (top == -1) ? i : i - st[top] - 1;
            int area = height * width;
            if (area > maxA) maxA = area;
        }
        st[++top] = i;
    }
    free(st);
    return maxA;
}

int maximalRectangle(char** matrix, int rows, int cols) {
    if (rows == 0) return 0;
    int* heights = (int*)calloc(cols, sizeof(int));
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        int area = largestHist(heights, cols);
        if (area > maxArea) maxArea = area;
    }
    free(heights);
    return maxArea;
}
