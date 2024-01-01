/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 *
 * [2706] 购买两块巧克力
 */

// @lc code=start
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        // // 1. 双重排序法 O(nlogn)
        // int minCost = INT_MAX;
        // for (int i = 0; i < prices.size(); ++i)
        // {
        //     for (int j = i + 1; j < prices.size(); ++j)
        //     {
        //         minCost = min(minCost, prices[i] + prices[j]);
        //     }
        // }
        // return money - minCost >= 0 ? money - minCost : money;

        // // 2. sort法 O(nlogn)
        // int minCost = INT_MAX;
        // sort(prices.begin(), prices.end());
        // return money - prices[0] - prices[1] >= 0
        //            ? money - prices[0] - prices[1]
        //            : money;

        // 3. 维护最小值和次小值法 O(n)
        int minCost = 0;
        int min_first = INT_MAX;
        int min_second = INT_MAX;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] <= min_first)
            {
                min_second = min_first;
                min_first = prices[i];
            }
            else if (prices[i] > min_first && prices[i] <= min_second)
            {
                min_second = prices[i];
            }
        }
        return money - min_first - min_second >= 0
                   ? money - min_first - min_second
                   : money;

        // // 4. dp动态规划 O(n)
        // vector<int> dp(prices.size() + 1, 0);
        // dp[1] = prices[0] + prices[1];
        // int minCostChocolate = min(prices[0], prices[1]);
        // for (int i = 2; i < prices.size(); ++i)
        // {
        //     if (prices[i] < minCostChocolate)
        //     {
        //         dp[i] = minCostChocolate + prices[i];
        //         minCostChocolate = prices[i];
        //     }
        //     else
        //     {
        //         dp[i] = min(dp[i - 1], minCostChocolate + prices[i]);
        //     }
        // }
        // return money - dp[prices.size() - 1] >= 0
        //            ? money - dp[prices.size() - 1]
        //            : money;
    }
};

// @lc code=end
