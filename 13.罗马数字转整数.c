/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (60.62%)
 * Likes:    786
 * Dislikes: 0
 * Total Accepted:    147.6K
 * Total Submissions: 243.4K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */

// @lc code=start
enum {
    ZERO, I, V, X, L, C, D, M,
};

int romanToInt(char * s){
    // 指向s末尾的指针
    int idx = strlen(s) - 1;
    int sum = 0;

    // int right = ZERO;
    // while (idx != -1) {
    //     switch (s[idx])
    //     {
    //     case 'I':
    //         sum = (right == V || right == X) ? sum - 1: sum + 1;
    //         idx--;
    //         right = I;
    //         break;
    //     case 'V':
    //         sum += 5;
    //         idx--;
    //         right = V;
    //         break;
    //     case 'X':
    //         sum = (right == L || right == C) ? sum - 10: sum + 10;
    //         idx--;
    //         right = X;
    //         break;
    //     case 'L':
    //         sum += 50;
    //         idx--;
    //         right = L;
    //         break;
    //     case 'C':
    //         sum = (right == D || right == M) ? sum - 100: sum + 100;
    //         idx--;
    //         right = C;
    //         break;
    //     case 'D':
    //         sum += 500;
    //         idx--;
    //         right = D;
    //         break;
    //     case 'M':
    //         sum += 1000;
    //         idx--;
    //         right = M;
    //         break;
        
    //     default:
    //         break;
    //     }
    // }

    while (idx != -1) {
        switch (s[idx])
        {
        case 'I':
            sum += 1;
            idx--;
            break;
        case 'V':
            sum += 5;
            idx--;
            if (idx == -1) break;
            if (s[idx] == 'I') {
                sum -= 1;
                idx--;
            }
            break;
        case 'X':
            sum += 10;
            idx--;
            if (idx == -1) break;
            if (s[idx] == 'I') {
                sum -= 1;
                idx--;
            }
            break;
        case 'L':
            sum += 50;
            idx--;
            if (idx == -1) break;
            if (s[idx] == 'X') {
                sum -= 10;
                idx--;
            }
            break;
        case 'C':
            sum += 100;
            idx--;
            if (idx == -1) break;
            if (s[idx] == 'X') {
                sum -= 10;
                idx--;
            }
            break;
        case 'D':
            sum += 500;
            idx--;
            if (idx == -1) break;
            if (s[idx] == 'C') {
                sum -= 100;
                idx--;
            }
            break;
        case 'M':
            sum += 1000;
            idx--;
            if (idx == -1) break;
            if (s[idx] == 'C') {
                sum -= 100;
                idx--;
            }
            break;
        
        default:
            break;
        }
    }
    return sum;
}


// @lc code=end

