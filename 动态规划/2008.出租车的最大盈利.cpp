/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 *
 * [2008] 出租车的最大盈利
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        vector<long long> dp(n + 1);
        // incomeTable：当乘客到达对应的end后，记录起点和收入
        vector<vector<pair<int, int>>> incomeTable(n + 1);
        for (auto &order: rides)
        {
            int start = order[0];
            int end = order[1];
            int tip = order[2];
            incomeTable[end].push_back(make_pair(start, end - start + tip));
        }
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1];
            // 查找表，找是否有终点站小于本次起点站的乘客
            for (auto &[st, ic]: incomeTable[i])
            {
                //dp[st]：终点站是start的乘客下车后，最大收入情况
                dp[i] = max(dp[i], dp[st] + ic);
            }
        }
        return dp[n];
    }
};

// @lc code=end
