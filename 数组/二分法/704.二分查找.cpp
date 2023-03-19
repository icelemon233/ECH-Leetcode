/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 左中右
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        // 循环：比mid小，右缩小；比mid大，左变大；mid二分，继续干
        // 注：二分法使用的均为left <= right
        while (left <= right)
        {
            if (target < nums[mid])
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
// @lc code=end
