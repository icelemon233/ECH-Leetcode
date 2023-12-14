/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> map(n);
        for (auto &connection : connections)
        {
            // 从0的角度出发，正向为1，反向为0
            // 那么从游客角度出发，正向道路数即需要变更方向的道路数
            map[connection[0]].push_back({connection[1], 1});
            map[connection[1]].push_back({connection[0], 0});
        }
        // function<bool(int, int)> dfs = [&](int x, int fa) -> bool
        function<int(int, int, vector<vector<pair<int, int>>> &)> dfs = [&](int nowRoad, int preCity, vector<vector<pair<int, int>>> &map) -> int
        {
            int result = 0;
            for (auto &city : map[nowRoad])
            {
                if (city.first == preCity)
                {
                    continue;
                }
                result += city.second + dfs(city.first, nowRoad, map);
            }
            return result;
        };
        return dfs(0, -1, map);
    }
};
// @lc code=end
