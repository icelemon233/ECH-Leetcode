/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 *
 * [2866] 美丽塔 II
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    // 美丽塔一句话总结：
    // 必须有一个峰顶，峰顶左右两侧必须单调向两边递减，且峰顶可以是最左边或最右边
    // 图像解释：
    //   *
    //  * *
    // *   *
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        //单调栈+前后缀解决
        int n = maxHeights.size();
        // 单调栈，存放下标
        stack<int> stack1, stack2;
        // 前后缀，存放高度和
        vector<long long> prefix(n), suffix(n);
        // 结果
        long long result = 0;

        // 假设当前maxHeights[i]为峰顶，计算前缀和
        for (int i = 0; i < n; ++i)
        {
            while (!stack1.empty() && maxHeights[stack1.top()] > maxHeights[i])
            {
                stack1.pop();
            }
            if (stack1.empty())
            {
                // 涉及maxHeights[i]的，都要做防溢出转换
                prefix[i] = (long long)(i + 1) * maxHeights[i];
            }
            else
            {
                // 当前栈顶为最小值，之后全部作为峰顶值处理
                prefix[i] = prefix[stack1.top()] +
                            (long long)(i - stack1.top()) * maxHeights[i];
            }
            stack1.emplace(i);
        }

        //假设当前maxHeights[i]为峰顶，计算后缀和，并同时计算结果
        for (int i = n - 1; i >= 0; --i)
        {
            while (!stack2.empty() && maxHeights[stack2.top()] > maxHeights[i])
            {
                stack2.pop();
            }
            if (stack2.empty())
            {
                suffix[i] = (long long)(n - i) * maxHeights[i];
            }
            else
            {
                // 当前栈顶为最小值，之后全部作为峰顶值处理
                suffix[i] = suffix[stack2.top()] +
                            (long long)(stack2.top() - i) * maxHeights[i];
            }
            stack2.emplace(i);
            // 由于前后缀重复计算了一次maxHeights[i]，要减去
            result = max(result, prefix[i] + suffix[i] - maxHeights[i]);
        }
        return result;
    }
};

// @lc code=end
