87. Scramble String

We can scramble a string s to get a string t using the following algorithm:
If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int memo[31][31][31];

bool solve(char* s1, int i1, char* s2, int i2, int len) {
    if (memo[i1][i2][len] != -1) return memo[i1][i2][len];

    bool match = true;
    for (int k = 0; k < len; k++) {
        if (s1[i1 + k] != s2[i2 + k]) {
            match = false;
            break;
        }
    }
    if (match) return memo[i1][i2][len] = 1;

    int count[26] = {0};
    for (int k = 0; k < len; k++) {
        count[s1[i1 + k] - 'a']++;
        count[s2[i2 + k] - 'a']--;
    }
    for (int k = 0; k < 26; k++) {
        if (count[k] != 0) return memo[i1][i2][len] = 0;
    }

    for (int k = 1; k < len; k++) {
        // No swap
        if (solve(s1, i1, s2, i2, k) && solve(s1, i1 + k, s2, i2 + k, len - k))
            return memo[i1][i2][len] = 1;
        // Swap
        if (solve(s1, i1, s2, i2 + len - k, k) && solve(s1, i1 + k, s2, i2, len - k))
            return memo[i1][i2][len] = 1;
    }

    return memo[i1][i2][len] = 0;
}

bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    memset(memo, -1, sizeof(memo));
    return solve(s1, 0, s2, 0, n);
}

int main() {
    char s1[] = "great", s2[] = "rgeat";
    if (isScramble(s1, s2)) printf("true\n");
    else printf("false\n");
    return 0;
}
