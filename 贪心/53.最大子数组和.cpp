/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 注意为什么result要设为最小int
        // 先判断count和result的大小，再判断count的正负。这样如果序列都为负数，result至少能够把最大的负数记录下来，后续count就能和暂时的最大值result作对比
        int result = INT_MIN;
        int count = 0;
        for (int &num : nums)
        {
            count += num;
            if (count > result)
            {
                result = count;
            }
            if (count < 0)
            {
                count = 0;
                continue;
            }
        }
        return result;
    }
};
// @lc code=end
