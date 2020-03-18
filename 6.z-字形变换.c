/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.65%)
 * Likes:    595
 * Dislikes: 0
 * Total Accepted:    104.6K
 * Total Submissions: 222.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start

#include <string.h>
#include <stdlib.h>

typedef struct _Character
{   
    char c;
    int idx;
}Character;


char * convert(char * s, int numRows){
    if (numRows == 1)
        return s;

    int len = strlen(s);
    int n = numRows - 1;
    char *str = (char*)malloc(sizeof(char) * (len + 1));

    int seg = n * 2;
    int idx_str = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < len; j++) {
            if (j % seg == i) 
                str[idx_str++] = s[j];
            else if (j % seg == seg - i) 
                str[idx_str++] = s[j];
        }
    }
    
    str[idx_str] = '\0';

    return str;
}

// @lc code=end

