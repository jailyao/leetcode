/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.86%)
 * Likes:    3163
 * Dislikes: 0
 * Total Accepted:    346.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
// int findCharInString(char *s, char c) {
//     int len = strlen(s);

//     for (int i = 0; i < len; i++) {
//         if (s[i] == c) {
//             return i;
//         }
//     }
//     return len;
// }

// int lengthOfLongestSubstring(char * s){
//     int head = 0, tail;
//     int subLen = 0, tmpLen = 0;
//     int strLen = strlen(s);
    
//     for (tail = 0; tail < strLen; tail++) {
//         tmpLen = tail - head;
//         int num = findCharInString(s + head, s[tail]);
//         if (num != tmpLen) {
//             if (subLen < tmpLen) {
//                 subLen = tmpLen;
//             }
//             head += (num + 1);
//         }
//     }

//     if (subLen < tail - head) {
//         subLen = tail - head;
//     }

//     return subLen;
// }

int lengthOfLongestSubstring(char * s){
    int head = 0, tail;
    int subLen = 0, tmpLen = 0;
    int strLen = strlen(s);

    char tailStr[2] = {'\0'};
    for (tail = 0; tail < strLen; tail++) {
        tailStr[0] = s[tail];
        tmpLen = tail - head;
        int num = strcspn(s + head, tailStr);
        if (num != tmpLen) {
            if (subLen < tmpLen) {
                subLen = tmpLen;
            }
            head += (num + 1);
        }
    }

    if (subLen < tail - head) {
        subLen = tail - head;
    }

    return subLen;
}


// @lc code=end

