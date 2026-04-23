68. Text Justification

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left-justified, and no extra space is inserted between words.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int size, int maxWidth, int* returnSize) {
    char** res = (char**)malloc(size * sizeof(char*));
    int i = 0, count = 0;

    while (i < size) {
        int len = strlen(words[i]);
        int j = i + 1;
        while (j < size && len + 1 + strlen(words[j]) <= maxWidth) {
            len += 1 + strlen(words[j]);
            j++;
        }

        char* line = (char*)malloc((maxWidth + 1) * sizeof(char));
        memset(line, 0, maxWidth + 1);
        int gaps = j - i - 1;

        if (j == size || gaps == 0) {
            int pos = 0;
            for (int k = i; k < j; k++) {
                strcpy(line + pos, words[k]);
                pos += strlen(words[k]);
                if (k < j - 1) line[pos++] = ' ';
            }
            while (pos < maxWidth) line[pos++] = ' ';
        } else {
            int totalSpaces = maxWidth - (len - gaps);
            int each = totalSpaces / gaps;
            int extra = totalSpaces % gaps;
            int pos = 0;
            for (int k = i; k < j; k++) {
                strcpy(line + pos, words[k]);
                pos += strlen(words[k]);
                if (k < j - 1) {
                    int s = each + (extra-- > 0 ? 1 : 0);
                    for (int space = 0; space < s; space++) line[pos++] = ' ';
                }
            }
        }
        res[count++] = line;
        i = j;
    }
    *returnSize = count;
    return res;
}

int main() {
    char* words[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int returnSize;
    char** result = fullJustify(words, 7, 16, &returnSize);
    for (int i = 0; i < returnSize; i++) printf("\"%s\"\n", result[i]);
    return 0;
}
