/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        // 题目规定n从2开始
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            // 对于每个数，都要从1开始计算递推公式（拆分）
            for (int j = 1; j <= i / 2; j++)
            {
                // 拆分为2个数：j*(i-j)
                // 拆分为3个数及以上：j*dp[i-j]
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
// @lc code=end
