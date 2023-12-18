/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // 不讲码德版本
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            result = max(result, nums[i + 1] - nums[i]);
        }
        return result;
        // todo 基数排序和桶排序
    }
};

// @lc code=end
