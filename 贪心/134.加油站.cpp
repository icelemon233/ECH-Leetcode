/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    // 思路分析法
    // int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    // {
    //     // 行驶过程中的最小油量
    //     int minGas = INT_MAX;
    //     // 总剩余油量
    //     int finalResidualGas = 0;
    //     for (int i = 0; i < gas.size(); i++)
    //     {
    //         finalResidualGas += gas[i] - cost[i];
    //         if (finalResidualGas < minGas)
    //         {
    //             minGas = finalResidualGas;
    //         }
    //     }

    //     // 1. 全程最小油量都不低于0，证明从0开始跑就可以无限续航
    //     if (minGas >= 0)
    //     {
    //         return 0;
    //     }
    //     // 2. 最终剩余油量小于0，证明加的油一定不够跑完全程
    //     if (finalResidualGas < 0)
    //     {
    //         return -1;
    //     }
    //     // 3. 从0往后（倒退回gas.size()-1），尝试从更远处出发来弥补缺的这部分油
    //     for (int i = gas.size() - 1; i > 0; i--)
    //     {
    //         minGas += gas[i] - cost[i];
    //         if (minGas >= 0)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // 贪心法
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 行驶过程中的剩余油量，小于0就重置
        int residualGas = 0;
        int startIndex = 0;
        // 总剩余油量
        int finalResidualGas = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            residualGas += gas[i] - cost[i];
            finalResidualGas += gas[i] - cost[i];
            if (residualGas < 0)
            {
                residualGas = 0;
                startIndex = i + 1;
            }
        }

        // 如果剩余油量小于0，则一定跑不完一圈
        // 反之证明一定能跑完一圈，开始的加油站下标就是startIndex
        if (finalResidualGas < 0)
        {
            return -1;
        }
        return startIndex;
    }
};
// @lc code=end
