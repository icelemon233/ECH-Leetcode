/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> nums1_set;
        for (int &num : nums1)
        {
            nums1_set.emplace(num);
        }
        // 检查nums2数组中是否与nums1有交叉
        // 这里不能用vector，否则不能自动去重
        unordered_set<int> ret_set;
        for (int &num : nums2)
        {
            if (nums1_set.find(num) != nums1_set.end())
            {
                ret_set.emplace(num);
            }
        }
        return vector<int>(ret_set.begin(), ret_set.end());
    }
};
// @lc code=end
