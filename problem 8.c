41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int firstMissingPositive(int* nums, int n) {
    for (int i = 0; i < n; i++) {
        // While the number is in range and not in its correct position
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(&nums[i], &nums[nums[i] - 1]);
        }
    }

    // Check which index does not contain the correct value
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    printf("%d\n", firstMissingPositive(arr, 4));
    return 0;
}
