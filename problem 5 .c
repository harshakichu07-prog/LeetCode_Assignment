30. Substring with Concatenation of All Words

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[100];
    int count;
} WordFreq;

int getFreq(WordFreq* arr, int size, char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].word, target) == 0) return arr[i].count;
    }
    return 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int n = strlen(s);
    int wordLen = strlen(words[0]);
    int totalWordsLen = wordLen * wordsSize;
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = 0;

    if (n < totalWordsLen) return result;

    WordFreq expected[wordsSize];
    int uniqueCount = 0;
    for (int i = 0; i < wordsSize; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(expected[j].word, words[i]) == 0) {
                expected[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(expected[uniqueCount].word, words[i]);
            expected[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    for (int i = 0; i < wordLen; i++) {
        int left = i, count = 0;
        WordFreq window[wordsSize];
        int windowUnique = 0;
        memset(window, 0, sizeof(window));

        for (int j = i; j <= n - wordLen; j += wordLen) {
            char sub[100] = {0};
            strncpy(sub, s + j, wordLen);
            
            int expFreq = getFreq(expected, uniqueCount, sub);
            if (expFreq > 0) {
                int winIdx = -1;
                for(int k=0; k<windowUnique; k++) 
                    if(strcmp(window[k].word, sub) == 0) winIdx = k;
                
                if (winIdx == -1) {
                    strcpy(window[windowUnique].word, sub);
                    window[windowUnique].count = 1;
                    winIdx = windowUnique++;
                } else window[winIdx].count++;
                
                count++;

                while (window[winIdx].count > expFreq) {
                    char leftSub[100] = {0};
                    strncpy(leftSub, s + left, wordLen);
                    for(int k=0; k<windowUnique; k++)
                        if(strcmp(window[k].word, leftSub) == 0) window[k].count--;
                    left += wordLen;
                    count--;
                }
                if (count == wordsSize) result[(*returnSize)++] = left;
            } else {
                memset(window, 0, sizeof(window));
                windowUnique = 0;
                count = 0;
                left = j + wordLen;
            }
        }
    }
    return result;
}
