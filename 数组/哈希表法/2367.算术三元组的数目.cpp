/*
 * @lc app=leetcode.cn id=2367 lang=cpp
 *
 * [2367] 算术三元组的数目
 */

// @lc code=start
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        unordered_set<int> hashSet;
        for (int num : nums)
        {
            hashSet.emplace(num);
        }
        int result = 0;
        for (int x : nums)
        {
            if (hashSet.count(x + diff) && hashSet.count(x + 2 * diff))
            {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end
