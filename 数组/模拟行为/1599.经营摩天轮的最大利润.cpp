/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        // 等待的游客
        int wait_list = 0;
        // 已经登舱的游客
        int cus_list = 0;
        // 轮转次数
        int rorate = 0;
        // int board_list = 0;
        // 利润
        int max_income = 0;
        // 最小次数
        int ret = 0;
        while (wait_list > 0 || rorate < customers.size())
        {
            if (rorate < customers.size())
            {
                wait_list += customers[rorate];
            }
            if (wait_list >= 4)
            {
                wait_list -= 4;
                cus_list += 4;
                // board_list++;
            }
            else
            {
                cus_list += wait_list;
                wait_list = 0;
            }
            rorate++;
            int income = cus_list * boardingCost - rorate * runningCost;
            if (income > max_income)
            {
                max_income = income;
                ret = rorate;
            }
        }
        return ret == 0 ? -1 : ret;
    }
};
// @lc code=end
