/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        // 循环：比mid小，右缩小；比mid大，左变大；mid二分，继续干
        // 注：二分法使用的均为left <= right
        while (left <= right)
        {
            // 防止溢出，等同于(left + right)/2
            int middle = left + ((right - left) / 2);
            if (target < nums[middle])
            {
                // 比mid小，右缩小
                right = middle - 1;
            }
            else if (target > nums[middle])
            {
                // 比mid大，左变大
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }

        // 分别处理如下四种情况
        // 1. 目标值在数组所有元素之前，这种情况right会变成-1，返回right + 1；
        // 2. 目标值等于数组中某一个元素，返回middle，上面已经处理完毕;
        // 3. 目标值插入数组中的位置 [left, right]，返回right + 1；
        // 4. 目标值在数组所有元素之后的情况 [left, right]，这种情况right会变成size-1，所以返回right + 1；
        // 综上所述

        return right + 1;
    }
};
// @lc code=end
