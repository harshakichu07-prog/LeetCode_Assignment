115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

#include <stdio.h>
#include <string.h>

int numDistinct(char* s, char* t) {
    int m = strlen(s), n = strlen(t);
    unsigned long long dp[m + 1][n + 1];

    // Initialize DP table with 0
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Base case: An empty t is a subsequence of any prefix of s in 1 way
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                // Option 1: Use s[i-1] + Option 2: Don't use s[i-1]
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                // Must skip s[i-1]
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return (int)dp[m][n];
}

int main() {
    char s[] = "rabbbit", t[] = "rabbit";
    printf("%d\n", numDistinct(s, t));
    return 0;
}
