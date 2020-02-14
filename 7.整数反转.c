/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start

#define INT_MAX (int)(2e31 - 1)
#define INT_MIN (int)(-2e31)

int reverse(int x){
    long oldNum = x;
    long newNum = 0;

    while (oldNum)
    {
        newNum *= 10;
        newNum += (oldNum % 10);
        oldNum /= 10;
    }

    if ((newNum > INT_MAX) || (newNum < INT_MIN)) {
        return 0;
    }

    return newNum;
}


// @lc code=end

