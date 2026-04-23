87. Scramble String

We can scramble a string s to get a string t using the following algorithm:
If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        unordered_map<string, bool> memo;
        return dfs(s1, s2, memo);
    }

private:
    bool dfs(const string& s1, const string& s2, unordered_map<string, bool>& memo) {
        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        if (s1 == s2) return memo[key] = true;
        if (s1.size() != s2.size()) return memo[key] = false;

        // quick pruning: character counts must match
        int count[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }

        int n = s1.size();
        for (int i = 1; i < n; i++) {
            // Case 1: no swap
            if (dfs(s1.substr(0, i), s2.substr(0, i), memo) &&
                dfs(s1.substr(i), s2.substr(i), memo)) {
                return memo[key] = true;
            }
            // Case 2: swap
            if (dfs(s1.substr(0, i), s2.substr(n - i), memo) &&
                dfs(s1.substr(i), s2.substr(0, n - i), memo)) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
};
