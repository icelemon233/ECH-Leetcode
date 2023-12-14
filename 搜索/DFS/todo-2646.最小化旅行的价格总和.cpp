/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 *
 * [2646] 最小化旅行的价格总和
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution
{
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        // 深搜+动态规划
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }

        vector<int> cnt(n);
        for (auto &t : trips)
        {
            int end = t[1];
            function<bool(int, int)> dfs = [&](int x, int fa) -> bool
            {
                if (x == end)
                {
                    cnt[x]++;
                    return true; // 找到 end
                }
                for (int y : g[x])
                {
                    if (y != fa && dfs(y, x))
                    {
                        cnt[x]++; // x 是 end 的祖先节点，也就在路径上
                        return true;
                    }
                }
                return false; // 未找到 end
            };
            dfs(t[0], -1);
        }

        // 类似 337. 打家劫舍 III
        function<pair<int, int>(int, int)> dfs = [&](int x, int fa) -> pair<int, int>
        {
            int not_halve = price[x] * cnt[x]; // x 不变
            int halve = not_halve / 2;         // x 减半
            for (int y : g[x])
            {
                if (y != fa)
                {
                    auto [nh, h] = dfs(y, x); // 计算 y 不变/减半的最小价值总和
                    not_halve += min(nh, h);  // x 不变，那么 y 可以不变，可以减半，取这两种情况的最小值
                    halve += nh;              // x 减半，那么 y 只能不变
                }
            }
            return {not_halve, halve};
        };
        auto [nh, h] = dfs(0, -1);
        return min(nh, h);
    }
};
// @lc code=end
