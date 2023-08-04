/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        // 邻接链表（同样的方法可以使用unordered_map格式）
        vector<vector<int>> vis(n);
        for (auto &path : paths)
        {
            vis[path[0] - 1].emplace_back(path[1] - 1);
            vis[path[1] - 1].emplace_back(path[0] - 1);
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
        {
            // 加上0一共有5种颜色
            vector<bool> flowerType(5, false);
            // 标注目前已使用的颜色
            for (auto &visGarden : vis[i])
            {
                // result[visGarden]表示邻接的花园所选取的颜色，那么本轮就不使用这个颜色
                flowerType[result[visGarden]] = true;
            }
            for (int j = 1; j <= 4; j++)
            {
                if (flowerType[j] == 0)
                {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end
