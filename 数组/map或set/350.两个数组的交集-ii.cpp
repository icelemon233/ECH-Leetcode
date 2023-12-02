/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nums1_map(1001);
        for (int &num : nums1)
        {
            nums1_map[num]++;
        }
        // 检查nums2数组中是否与nums1有交叉
        // 这里不能用vector，否则不能自动去重
        vector<int> ret;
        for (int &num : nums2)
        {
            if (nums1_map[num] > 0)
            {
                ret.emplace_back(num);
                nums1_map[num]--;
            }
        }
        return ret;
    }
};
// @lc code=end
