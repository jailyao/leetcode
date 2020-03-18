/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.82%)
 * Likes:    1443
 * Dislikes: 0
 * Total Accepted:    228K
 * Total Submissions: 554.2K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start


bool isValid(char * s){
    int len = strlen(s);
    if (len % 2) 
        return 0;

    char *sS = (char *)malloc(sizeof(char) * (len + 1));
    int sp = -1;

    while (*s != '\0') {
        if (*s == ')') 
            if ((sp < 0) || (sS[sp] != '(')) 
                return 0;
            else 
                sp--;
        else if (*s == ']') 
            if ((sp < 0) || (sS[sp] != '['))
                return 0;
            else 
                sp--;
        else if (*s == '}') 
            if ((sp < 0) || (sS[sp] != '{'))
                return 0;
            else 
                sp--;
        else 
            sS[++sp] = *s;
        s++;
    }
    if (sp != -1)
        return 0;

    return 1;
}


// @lc code=end

