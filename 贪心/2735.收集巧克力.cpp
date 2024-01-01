/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    // 题干更改（什么垃圾翻译）
    // 1. 一张桌子上有N件商品，它们围成一圈。每件商品的位置上都有一个价格标签，这个价格标签不跟随商品，而是固定位置的，价格标签的构成数组nums。
    // 2. 按照价格标签买该位置上的东西
    // 3. 还可以花x块钱把商品转一下，这样每件商品的价格就变成了下一个价格标签上的价格
    // Q：把每种商品买一遍，最少成本是多少？
    long long minCost(vector<int> &nums, int x)
    {
        int n = nums.size();
        // eachMinCost[i]代表第i种巧克力的最低成本
        vector<int> eachMinCost(nums);
        // 0LL代表long long(0)
        // totalCost：总成本
        // 这里已经计算了最初的总成本，即不执行转盘操作（0次）
        long long totalCost =
            accumulate(eachMinCost.begin(), eachMinCost.end(), 0LL);
        // 遍历转1次到转n-1次，转n次等同于不执行，之后重复，所以n后面就没必要算了
        for (int k = 1; k < n; ++k)
        {
            // 对于每一件商品，执行k次转盘操作时，计算一次最小的成本
            for (int i = 0; i < n; ++i)
            {
                eachMinCost[i] = min(eachMinCost[i], nums[(i + k) % n]);
            }
            // static_cast<long long>(k) * x ：转动k次的成本
            // 然后再计算总成本
            totalCost = min(
                totalCost,
                static_cast<long long>(k) * x +
                    accumulate(eachMinCost.begin(), eachMinCost.end(), 0LL));
        }
        return totalCost;
    }
};

// @lc code=end
