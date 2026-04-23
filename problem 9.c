42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

#include <stdio.h>

int trap(int* h, int n) {
    int l = 0, r = n - 1;
    int lMax = 0, rMax = 0, total = 0;

    while (l <= r) {
        if (h[l] < h[r]) {
            if (h[l] >= lMax) lMax = h[l];
            else total += lMax - h[l];
            l++;
        } else {
            if (h[r] >= rMax) rMax = h[r];
            else total += rMax - h[r];
            r--;
        }
    }
    return total;
}

int main() {
    int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(h, 12));
    return 0;
}
