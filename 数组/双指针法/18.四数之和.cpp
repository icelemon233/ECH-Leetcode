/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            // 排序之后，在正数范围的target内，如果第一个元素已经大于target，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if ((nums[i] > target) && (nums[i] > 0))
            {
                return ret;
            }
            // 如果这次的nums[i]与上一次的nums[i - 1]相同，可以直接跳过
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int k = i + 1; k < nums.size(); k++)
            {
                // 如果这次的nums[i]与上一次的nums[i - 1]相同，可以直接跳过
                if (k > i + 1 && nums[k] == nums[k - 1])
                {
                    continue;
                }
                int left = k + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[i] + nums[k] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[i] + nums[k] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        ret.emplace_back(vector<int>{nums[i], nums[k], nums[left], nums[right]});
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
        }
        return ret;
    }
};
// @lc code=end
