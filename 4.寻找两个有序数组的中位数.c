/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.79%)
 * Likes:    2159
 * Dislikes: 0
 * Total Accepted:    142.1K
 * Total Submissions: 386.1K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize = nums1Size + nums2Size;
    int halfSize = (nums1Size + nums2Size + 2) / 2;
    int newNums[halfSize];

    for (int k = 0, i = 0, j = 0; k < halfSize; ++k) {
        if ((i < nums1Size) && (j < nums2Size)) {
            newNums[k] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        } else if ((i < nums1Size)) {
            newNums[k] = nums1[i++];
        } else if ((j < nums2Size)) {
            newNums[k] = nums2[j++];
        } 
    }

    if (totalSize % 2) {
        return newNums[halfSize - 1];
    } else {
        return ((newNums[halfSize - 2] + newNums[halfSize - 1]) / 2.0);
    }
}


// @lc code=end

