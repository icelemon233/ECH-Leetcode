/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int m = rowSum.size();
        int n = colSum.size();
        // 思路：从左上角开始，填上允许的最大值（包括行和列的限制），消掉一行或一列，剩下以此类推
        vector<vector<int>> ret(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (rowSum[i] < colSum[j])
            {
                // 该行已被消除（同行其他值默认为0），列需要减去已经填上的值
                colSum[j] -= rowSum[i];
                ret[i++][j] = rowSum[i];
            }
            else
            {
                // 该列已被消除（同列其他值默认为0），行需要减去已经填上的值
                rowSum[i] -= colSum[j];
                ret[i][j++] = colSum[j];
            }
        }
        return ret;
    }
};
// @lc code=end
