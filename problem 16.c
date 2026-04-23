84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int n) {
    int* st = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int h = (i == n ? 0 : heights[i]);
        
        while (top != -1 && h < heights[st[top]]) {
            int height = heights[st[top--]];
            int width = (top == -1) ? i : i - st[top] - 1;
            int area = height * width;
            if (area > maxArea) maxArea = area;
        }
        st[++top] = i;
    }
    
    free(st);
    return maxArea;
}

int main() {
    int h[] = {2, 1, 5, 6, 2, 3};
    printf("%d\n", largestRectangleArea(h, 6));
    return 0;
}
