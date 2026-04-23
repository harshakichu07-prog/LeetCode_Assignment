4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* n1, int s1, int* n2, int s2) {
    if (s1 > s2) return findMedianSortedArrays(n2, s2, n1, s1);

    int low = 0, high = s1;
    int half = (s1 + s2 + 1) / 2;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = half - i;

        int l1 = (i == 0) ? INT_MIN : n1[i - 1];
        int r1 = (i == s1) ? INT_MAX : n1[i];
        int l2 = (j == 0) ? INT_MIN : n2[j - 1];
        int r2 = (j == s2) ? INT_MAX : n2[j];

        if (l1 <= r2 && l2 <= r1) {
            if ((s1 + s2) % 2 == 0) {
                int maxL = (l1 > l2) ? l1 : l2;
                int minR = (r1 < r2) ? r1 : r2;
                return (maxL + minR) / 2.0;
            } else {
                return (double)((l1 > l2) ? l1 : l2);
            }
        } else if (l1 > r2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0;
}

int main() {
    int a[] = {1, 3}, b[] = {2};
    printf("%f", findMedianSortedArrays(a, 2, b, 1));
    return 0;
}
