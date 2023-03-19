/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        // 双指针移除类模板
        while (fast < nums.size())
        {
            if (nums[fast] != 0)
            {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        // 补0
        while (slow < nums.size())
        {
            nums[slow++] = 0;
        }
    }
};
// @lc code=end
