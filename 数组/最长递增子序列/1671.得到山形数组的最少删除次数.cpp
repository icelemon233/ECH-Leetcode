/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
#include <algorithm>
#include <limits>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    // LIS: Long Increase Sequence
    vector<int> getLISArray(const vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            // 从j到i严格递增
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }

    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftLIS = getLISArray(nums);
        reverse(nums.begin(), nums.end());
        vector<int> rightLIS = getLISArray(nums);
        reverse(rightLIS.begin(),
                rightLIS.end());    // 两次reverse就是从后到前的顺序
        int result = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            // >1表示以当前下标i作为峰顶元素的情况下，两边是符合山形的
            if (leftLIS[i] > 1 && rightLIS[i] > 1)
            {
                // 越多的山形就代表要删除的元素越少，所以这里用max
                result = max(result, leftLIS[i] + rightLIS[i] - 1);
            }
        }
        return n - result;
    }
};

// @lc code=end
