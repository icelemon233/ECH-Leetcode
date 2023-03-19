/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0)
            {
                return ret;
            }
            // 如果这次的nums[i]与上一次的nums[i - 1]相同，可以直接跳过
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    ret.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重，移动到相同数的最后一个，那么再下一步指针同时移动就可以得到不同值的left和right
                    // 对于left，如果下一个left与这个相同，则跳过（left+1=left）
                    while (left < right && nums[left + 1] == nums[left])
                    {
                        left++;
                    }
                    // 对于right，如果下一个right与这个相同，则跳过（right-1=right）
                    while (left < right && nums[right - 1] == nums[right])
                    {
                        right--;
                    }

                    // 找到答案时，双指针同时收缩
                    left++;
                    right--;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
