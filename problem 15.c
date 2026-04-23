76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int s_len = strlen(s), t_len = strlen(t);
    if (s_len == 0 || t_len == 0) return "";

    int need[128] = {0}, window[128] = {0};
    int t_distinct = 0;
    for (int i = 0; i < t_len; i++) {
        if (need[(int)t[i]] == 0) t_distinct++;
        need[(int)t[i]]++;
    }

    int left = 0, right = 0, valid = 0;
    int start = 0, min_len = INT_MAX;

    while (right < s_len) {
        char c = s[right];
        right++;
        if (need[(int)c] > 0) {
            window[(int)c]++;
            if (window[(int)c] == need[(int)c]) valid++;
        }

        while (valid == t_distinct) {
            if (right - left < min_len) {
                start = left;
                min_len = right - left;
            }
            char d = s[left];
            left++;
            if (need[(int)d] > 0) {
                if (window[(int)d] == need[(int)d]) valid--;
                window[(int)d]--;
            }
        }
    }

    if (min_len == INT_MAX) return "";
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, s + start, min_len);
    result[min_len] = '\0';
    return result;
}

int main() {
    char s[] = "ADOBECODEBANC", t[] = "ABC";
    printf("%s\n", minWindow(s, t));
    return 0;
}
