/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution
{
public:
    // i，j为合并堆的起始和末尾，p为stone[i]到stone[j]所要合成的堆数
    int dfs(vector<vector<int>> &dp, vector<int> &preFix, int k, int i, int j)
    {
        if (i == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        dp[i][j] = INT_MAX;
        // 枚举哪些石头堆合并成第一堆
        for (int m = i; m < j; m += k - 1)
        {
            dp[i][j] = min(dp[i][j], dfs(dp, preFix, k, i, m) + dfs(dp, preFix, k, m + 1, j));
        }
        // 可以合并成一堆
        if ((j - i) % (k - 1) == 0)
        {
            dp[i][j] += preFix[j + 1] - preFix[i];
        }
        return dp[i][j];
    }

    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1)) // 无法合并成一堆
            return -1;

        // 前缀和
        vector<int> preFix(n + 1, 0);
        preFix[0] = 0;
        for (int i = 0; i < n; i++)
        {
            preFix[i + 1] = preFix[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return dfs(dp, preFix, k, 0, n - 1);
    }
};
// @lc code=end
