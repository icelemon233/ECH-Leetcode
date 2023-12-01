/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            // dp[i + 1] = 0;
            // 记录从i-k到i的下标中最大的值
            int subMaxNum = 0;
            // j的范围从i-k到i
            for (int j = i; j > i - k && j >= 0; j--)
            {
                subMaxNum = max(subMaxNum, arr[j]);
                // j到i下标的元素全部变为subMaxNum
                dp[i + 1] = max(dp[i + 1], dp[j] + (i - j + 1) * subMaxNum);
            }
        }
        return dp[n];
    }
};
// @lc code=end
