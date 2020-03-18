/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.12%)
 * Likes:    915
 * Dislikes: 0
 * Total Accepted:    206.9K
 * Total Submissions: 565.8K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) 
        return "";

    int strLen = strlen(strs[0]);
    int comIdx = strLen - 1;
    int endIdx = strLen;
    char *comStr = (char *)malloc(sizeof(char) * (strLen + 1));
    strcpy(comStr, strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int maxComIdx = comIdx;
        for (int j = 0; j <= maxComIdx; j++) {
            if (strs[i][j] == comStr[j]) {
                comIdx = j;
            } else {
                comIdx = j - 1;
                break;
            }
        }

        if (endIdx > comIdx + 1) {
            endIdx = comIdx + 1;
        }
    }

    comStr[endIdx] = '\0';
    return comStr;
}


// @lc code=end

