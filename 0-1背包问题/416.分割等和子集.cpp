/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 如果元素小于两个，直接判定false
        if (nums.size() < 2)
        {
            return false;
        }
        // 计算元素和，保存最大元素
        int sum = 0;
        int maxNum = 0;
        for (int num : nums)
        {
            sum += num;
            maxNum = max(maxNum, num);
        }
        // 如果最大元素超过一半，直接判定false
        // 如果元素和为偶数，直接判定false
        if (sum % 2 == 1 || maxNum > sum / 2)
        {
            return false;
        }

        // 01背包问题：将nums中的物品尽可能地放入背包，背包容量必须为sum/2
        // 全部初始化为0
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        // 集合中的元素正好可以凑成总和target
        if (dp[target] == target)
        {
            return true;
        }
        // 否则返回false
        return false;
    }
};
// @lc code=end
