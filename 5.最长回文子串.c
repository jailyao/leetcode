/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */
#include <string.h>
// @lc code=start
int oddPalindrome(char *s, int len) {
    int i = 0;
    for (; i <= len; i++) {
        if (s[-i] != s[i])
            break;
    }
    return i - 1;
}

int evenPalindrome(char *s, int len) {
    int i = 0;
    for (; i <= len; i++) {
        if (s[-i] != s[i + 1])
            break;
    }
    return i - 1;
}
#define MAX_CHARS   1001
char * longestPalindrome(char * s){
    char *subStr = (char *)calloc(sizeof(char), 1001);
    int len = strlen(s);
    int subStart, subLen;

    // start
    if (s) {
        subStart = 0;
        subLen = 1;
    }

    // odd
    for (int i = 1; i < len - 1; i++) {
        if (s[i - 1] == s[i + 1]) {      
            int maxLen = (len - 1 - i > i ? i : len - 1 - i);
            int tmp = oddPalindrome(&s[i], maxLen);
            int tmpLen = 2 * tmp + 1;
            if (subLen < tmpLen) {
                subLen = tmpLen;
                subStart = i - tmp;
            }
        }
    }

    // even
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {             
            int maxLen = (len - 2 - i > i ? i : len - 2 - i);
            int tmp = evenPalindrome(&s[i], maxLen);
            int tmpLen = 2 * tmp + 2;
            if (subLen < tmpLen) {
                subLen = tmpLen;
                subStart = i - tmp;
            }
        } 
    }

    strncpy(subStr, s + subStart, subLen);
    return subStr;
}


// @lc code=end

