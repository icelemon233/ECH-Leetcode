/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 */

// @lc code=start
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> map;
        for (int i = 0; i < m; i++)
        {
            string s = string(n, '0');
            for (int j = 0; j < n; j++)
            {
                // 记录同组元素（比如001和110，且key统一以0开头
                // 所以如果 matrix[i][0] 为 1，则对该行元素进行翻转
                s[j] = '0' + (matrix[i][j] ^ matrix[i][0]);
            }
            map[s]++;
        }
        int result = 0;
        for (auto &[k, v] : map)
        {
            result = max(res, v);
        }
        return result;
    }
};
// @lc code=end
