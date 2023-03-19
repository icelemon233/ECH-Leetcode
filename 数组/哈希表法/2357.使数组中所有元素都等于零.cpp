/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> nums_list;
        for (int &num : nums)
        {
            if (num > 0)
            {
                nums_list.emplace(num);
            }
        }
        return nums_list.size();
    }
};
// @lc code=end
