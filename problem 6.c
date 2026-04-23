32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    int maxLen = 0;
    int* st = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;

    // Push -1 as the initial base index
    st[++top] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            // Push index of opening parenthesis
            st[++top] = i;
        } else {
            // Pop the last opening bracket index
            top--;
            if (top == -1) {
                // If empty, push current index as the new base
                st[++top] = i;
            } else {
                // Calculate length using current index and new top
                int currentLen = i - st[top];
                if (currentLen > maxLen) maxLen = currentLen;
            }
        }
    }

    free(st);
    return maxLen;
}

int main() {
    char* s = ")()())";
    printf("%d\n", longestValidParentheses(s));
    return 0;
}
