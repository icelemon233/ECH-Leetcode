/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // 题目转化两个背包，第一个背包装+数，第二个背包装-数
        // 那么p1-p2就是nums的sum，p1+p2就是target
        // 那么p1 = sum + p2 = sum + target - p1
        // 所以p1 = (sum + target) / 2
        // 题目转化为求nums背包里挑多少个数能符合p1这个值的要求
        // 01背包问题：将nums中的物品尽可能地放入背包，背包容量必须为(sum + target) / 2
        // 全部初始化为0
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        // 如果元素和比原目标还要小，证明全加或全减也凑不到，没有方案
        if (abs(target) > sum)
            return 0;
        // 由前面的题意，p2 = (sum - target) / 2
        // 那么如果sum + target或sum - target不是偶数，证明p1和p2是非整数，不可能出现，也没有方案
        if ((target + sum) % 2 == 1 || (target - sum) % 2 == 1)
            return 0;
        int newTarget = (sum + target) / 2;
        vector<int> dp(newTarget + 1, 0);
        // 此处必须初始化dp[0]为1
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = newTarget; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newTarget];
    }
};
// @lc code=end
