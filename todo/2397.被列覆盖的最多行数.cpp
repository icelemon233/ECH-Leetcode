/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
private:
    int maxRows = 0;    // 覆盖最大行数，初始为0

    /**
     * 对当前idx列有选与不选两种选择
     * @param masks: 每一行的数字掩码
     * @param numSelect: 当前还可以选择的列数
     * @param n: 总列数，也是列索引上界
     * @param idx：当前处理的列索引
     * @param s: 选择的列集合掩码
    */
    void backtracking(vector<int> &masks, int numSelect, int n, int idx, int s)
    {
        if (numSelect == 0)
        {
            int coverRows = 0;
            for (auto &mask: masks)
            {
                // mask & ~s 如果选择的列在该行为1，置为0
                // 如果结果为0，说明当前行所有列都为0，该行被覆盖，行数+1；否则该行未被覆盖，行数+0
                coverRows += 1 - min(1, mask & ~s);
            }
            maxRows = max(maxRows, coverRows);    // 可以选择的列数为0，更新最大覆盖行数
            return;
        }
        if (idx == n)    // 列索引到达上界
        {
            return;
        }
        backtracking(masks, numSelect, n, idx + 1, s);        // 不选当前列，直接递归
        s |= (1 << idx);                                      // 选择当前列，将当前列在s中的对应位置1
        backtracking(masks, numSelect - 1, n, idx + 1, s);    // 选择当前列后，递归处理
    }

public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> masks(m, 0);    // 存储每一行的数字掩码
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                masks[i] |= (matrix[i][j] << j);    // 生成每一行的数字掩码，将第j个数字添加到mask从右往左的第j位
            }
        }
        backtracking(masks, numSelect, n, 0, 0);    // 回溯枚举所有的列选择集合，统计覆盖最大行数
        return maxRows;
    }
};

// @lc code=end
