/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        // 二元一次方程
        // 设材料可以完美制作x个巨无霸，y个小皇堡
        // 那么
        // 4x + 2y = tomatoSlices
        // x + y = cheeseSlices
        // 解得
        // x = 0.5 * tomatoSlices - cheeseSlices
        // y = 2 * cheeseSlices - 0.5 * tomatoSlices
        // 使用int得出最后结果，并以此计算需要多少原材料数
        // 如果符合原材料数，那么符合要求；否则证明会剩下原料，返回{}
        int total_jumbo = 0.5 * tomatoSlices - cheeseSlices;
        int total_small = 2 * cheeseSlices - 0.5 * tomatoSlices;
        if (total_jumbo * 4 + total_small * 2 == tomatoSlices &&
            total_jumbo + total_small == cheeseSlices && total_jumbo >= 0 &&
            total_small >= 0)
        {
            return {total_jumbo, total_small};
        }
        else
        {
            return {};
        }
    }
};

// @lc code=end
