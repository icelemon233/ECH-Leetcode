/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 *
 * [2477] 到达首都的最少油耗
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution
{
private:
    long long result = 0;

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        // 构造邻接矩阵
        int n = roads.size(); // 题目已说明恰好有n-1条路，所以有n个节点
        vector<vector<int>> map(n + 1);
        for (auto &road : roads)
        {
            map[road[0]].push_back(road[1]);
            map[road[1]].push_back(road[0]);
        }
        // 此处用function写，重新写一个函数会麻烦很多
        function<int(int, int)> dfs = [&](int nowCity, int lastCity) -> int
        {
            // 每个节点都有一个城市代表，如果这里写0就会导致后续迭代都是0，无法增加人数
            // 如果写1，最后要记得计算人数的时候-1，因为一开始首都节点不算人数
            int person = 1;
            for (auto &subRoad : map[nowCity])
            {
                if (subRoad != lastCity)
                {
                    int personSum = dfs(subRoad, nowCity);
                    person += personSum;
                    // 对应上文，这里减掉1
                    // 为什么用personSum：只计算该边有多少个城市代表会到达
                    result += (personSum + seats - 1) / seats;
                }
            }
            return person;
        };
        dfs(0, -1);
        return result;
    }
};
// @lc code=end
