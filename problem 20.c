123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int n) {
    if (n == 0) return 0;

    int hold1 = INT_MIN, sell1 = 0;
    int hold2 = INT_MIN, sell2 = 0;

    for (int i = 0; i < n; i++) {
        int p = prices[i];

        // First Transaction
        if (-p > hold1) hold1 = -p;
        if (hold1 + p > sell1) sell1 = hold1 + p;

        // Second Transaction
        if (sell1 - p > hold2) hold2 = sell1 - p;
        if (hold2 + p > sell2) sell2 = hold2 + p;
    }

    return sell2;
}

int main() {
    int p[] = {3, 3, 5, 0, 0, 3, 1, 4};
    printf("%d\n", maxProfit(p, 8));
    return 0;
}
