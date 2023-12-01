/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] 工作计划的最低难度
 */

// @lc code=start
class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
        {
            return -1;
        }
        vector<vector<int>> dp(d, vector<int>(n, 0x3f3f3f3f));
        dp[0][0] = jobDifficulty[0];
        // 当只有一天的时候，全部做完工作，就是取jobDifficulty数组中最大的难度值
        for (int x = 1; x < n; x++)
        {
            dp[0][x] = max(dp[0][x - 1], jobDifficulty[x]);
        }
        for (int i = 1; i < d; i++)
        {
            //如果增加一天，那么计算剩下的
            for (int j = n - 1; j >= i; j--)
            {
                int maxjD = 0;
                for (int k = j; k >= i; k--)
                {
                    maxjD = max(maxjD, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + maxjD);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};
// @lc code=end
