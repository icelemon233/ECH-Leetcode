/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<int> &values, vector<vector<int>> &memoryVec, int i, int j)
    {
        // 只有两个点，无法组成三角形
        if (i + 1 == j)
        {
            return 0;
        }
        if (memoryVec[i][j] != -1)
        {
            return memoryVec[i][j];
        }
        memoryVec[i][j] = INT_MAX;
        // 枚举顶点 k
        for (int k = i + 1; k < j; ++k)
        {
            memoryVec[i][j] = min(memoryVec[i][j], dfs(values, memoryVec, i, k) + dfs(values, memoryVec, k, j) + values[i] * values[j] * values[k]);
        }
        return memoryVec[i][j];
    }

    int minScoreTriangulation(vector<int> &values)
    {
        // 假定多边形其中的三个点i,j,k
        // i和j相邻，k为除此之外的点
        // 深搜+递归，假设函数为dfs()
        // 取最小的dfs(从i到k的多边形得分）+dfs（从k到j的多边形得分）+ijk组成的三角形得分

        vector<vector<int>> memoryVec(values.size(), vector<int>(values.size(), -1));
        return dfs(values, memoryVec, 0, values.size() - 1);
    }
};
// @lc code=end
