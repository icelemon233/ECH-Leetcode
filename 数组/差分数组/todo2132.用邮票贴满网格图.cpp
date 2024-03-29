/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 *
 * [2132] 用邮票贴满网格图
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    bool
    possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
    {
        int m = grid.size(), n = grid[0].size();

        // 1. 计算 grid 的二维前缀和
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s[i + 1][j + 1] =
                    s[i + 1][j] + s[i][j + 1] - s[i][j] + grid[i][j];
            }
        }

        // 2. 计算二维差分
        // 为方便第 3 步的计算，在 d 数组的最上面和最左边各加了一行（列），所以下标要 +1
        vector<vector<int>> d(m + 2, vector<int>(n + 2));
        for (int i2 = stampHeight; i2 <= m; i2++)
        {
            for (int j2 = stampWidth; j2 <= n; j2++)
            {
                int i1 = i2 - stampHeight + 1;
                int j1 = j2 - stampWidth + 1;
                if (s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] +
                        s[i1 - 1][j1 - 1] ==
                    0)
                {
                    d[i1][j1]++;
                    d[i1][j2 + 1]--;
                    d[i2 + 1][j1]--;
                    d[i2 + 1][j2 + 1]++;
                }
            }
        }

        // 3. 还原二维差分矩阵对应的计数矩阵（原地计算）
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];
                if (grid[i][j] == 0 && d[i + 1][j + 1] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// @lc code=end
