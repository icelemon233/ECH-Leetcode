/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        // 计算全部石头重量
        int weight = 0;
        for (int stone : stones)
        {
            weight += stone;
        }
        // 01背包问题：将石头尽可能地放入背包，背包最大重量为weight/2
        // 全部初始化为0
        int target = weight / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        // weight减去背包里的石头堆A，就是剩余石头堆B
        // weightB = weight-weightA
        // 由于weight / 2向下取整，石头堆A一定比石头堆B轻
        // 因此weightB > weightA，所以结果就是weightB-weightA = weight-weightA-weightA
        return weight - dp[target] - dp[target];
    }
};
// @lc code=end
