/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        // dp[i]表示某一边子树中i个元素能构成的搜索树数量
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                // 两边子树的元素数量分别是i-j和j-1（除掉树顶节点，就剩下i-1个节点）
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end
