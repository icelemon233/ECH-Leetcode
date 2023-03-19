/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int ret = 0;
        // 邻接矩阵表
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        // 表各行各列的和（度）
        vector<int> degree(n, 0);
        // 邻接矩阵
        for (auto &road : roads)
        {
            adj[road[0]][road[1]] = true;
            adj[road[1]][road[0]] = true;
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // 检测最多道路的两个城市（十字）
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ret = max(ret, degree[i] + degree[j] - (adj[i][j] ? 1 : 0));
            }
        }
        return ret;
    }
};
// @lc code=end
