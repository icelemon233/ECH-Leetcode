/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
        // 方便处理 nums[-1] 以及 nums[n] 的边界情况
        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == nums.size())
            {
                return {0, 0};
            }
            return {1, nums[i]};
        };

        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (get(mid) > get(mid - 1) && get(mid) > get(mid + 1))
            {
                result = mid;
                return result;
            }
            // 如果不符合峰值元素，哪边大往哪边找，就变成了二分查找
            if (get(mid) < get(mid + 1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};

// @lc code=end
