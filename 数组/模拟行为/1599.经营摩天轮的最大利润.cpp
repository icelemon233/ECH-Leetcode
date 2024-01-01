/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers,
                               int boardingCost,
                               int runningCost)
    {
        // 等待游客人数和已登舱游客人数
        int waiting_list = 0, served_list = 0;
        // 当前已轮转次数和最小轮转次数
        int rorate = 0, min_rorate = -1;
        // 总利润
        int total_income = 0, max_income = 0;
        // 模拟：先遍历customers，如果还有剩下的游客也进行同样的计算
        for (auto &customer: customers)
        {
            // 游客抵达
            waiting_list += customer;
            // 登舱，并记录轮转一次
            total_income += min(waiting_list, 4) * boardingCost - runningCost;
            waiting_list -= min(waiting_list, 4);
            rorate++;
            // 记录最大利润
            if (total_income > max_income)
            {
                max_income = total_income;
                min_rorate = rorate;
            }
        }
        while (waiting_list > 0)
        {
            // 剩余游客的计算
            // 登舱，并记录轮转一次
            total_income += min(waiting_list, 4) * boardingCost - runningCost;
            waiting_list -= min(waiting_list, 4);
            rorate++;
            // 记录最大利润
            if (total_income > max_income)
            {
                max_income = total_income;
                min_rorate = rorate;
            }
        }
        return min_rorate;
    }
};

// @lc code=end
