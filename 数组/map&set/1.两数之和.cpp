/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> nums_map;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = nums_map.find(target - nums[i]);
            if (it != nums_map.end())
            {
                ret.emplace_back(i);
                ret.emplace_back(it->second);
                return ret;
            }
            nums_map.emplace(nums[i], i);
        }
        return ret;
    }
};
// @lc code=end
