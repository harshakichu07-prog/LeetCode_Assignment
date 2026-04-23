123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold1 = INT_MIN, sell1 = 0;
        int hold2 = INT_MIN, sell2 = 0;

        for (int price : prices) {
            hold1 = max(hold1, -price);
            sell1 = max(sell1, hold1 + price);
            hold2 = max(hold2, sell1 - price);
            sell2 = max(sell2, hold2 + price);
        }

        return sell2;
    }
};
