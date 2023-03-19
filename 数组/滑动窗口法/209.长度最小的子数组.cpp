/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 快速判断
        if (nums.size() == 1)
        {
            if (nums[0] != target)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        // 定义快慢指针和滑动窗口数值和
        int fast = 0;
        int slow = 0;
        int temp_sums = 0;
        // 记录长度最小的连续子数组
        int min_length = INT_MAX;
        while (fast < nums.size())
        {
            temp_sums += nums[fast];
            while (temp_sums >= target)
            {
                if (fast - slow + 1 < min_length)
                {
                    min_length = fast - slow + 1;
                }
                temp_sums -= nums[slow++];
            }
            fast++;
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};
// @lc code=end
