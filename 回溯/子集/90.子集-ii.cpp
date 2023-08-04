/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    // 如果不想在backTracking里面剪枝，可以用set特性去重
    // unordered_set<vector<int>> set;

public:
    void backTracking(vector<int> &nums, int startIndex)
    {
        if (startIndex > nums.size() - 1)
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            // 对后面重复的元素进行跳过
            if (i > startIndex && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            result.push_back(path);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }
        result.push_back({});
        sort(nums.begin(), nums.end()); // 去重需要排序
        backTracking(nums, 0);
        return result;
    }
};
// @lc code=end
