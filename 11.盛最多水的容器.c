/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (61.20%)
 * Likes:    1206
 * Dislikes: 0
 * Total Accepted:    157K
 * Total Submissions: 253K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 
 */

// @lc code=start
int max(int a, int b) {
    return (a > b ? a : b);
}

int min(int a, int b) {
    return (a < b ? a : b);
}


int maxArea(int* height, int heightSize){
    int areaSize = 0;

    // 双指针 O(n)
    int left = 0, right = heightSize - 1;
    while (right > left) {
        int hl = height[left];
        int hr = height[right];
        areaSize = max((right - left) * min(hl, hr), areaSize);
        if (hl > hr) 
            right--;
        else 
            left++;
    }

    // 暴力 O(n2)
    // for (int i = 0; i < heightSize - 1; i++) {
    //     int h1 = height[i];
    //     for (int j = i + 1; j < heightSize; j++) {
    //         int h2 = height[j];
    //         areaSize = max((j - i) * min(h1, h2), areaSize);
    //     }
    // }

    return areaSize;
}


// @lc code=end

