/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backTracking(vector<int> &nums, int startIndex)
    {
        // 注意这里不要加return，因为要取树上的所有节点
        if (path.size() > 1)
        {
            result.push_back(path);
        }
        // 使用set对本层元素进行去重
        unordered_set<int> used_set;
        for (int i = startIndex; i < nums.size(); i++)
        {
            // 1. path不为空且后面的数比前面的数小（path为空就跳过会使得第一个元素无法加进path里）
            // 2. 该元素已经被使用过
            // 满足以上两个条件之一都跳过
            if ((!path.empty() && nums[i] < path.back()) || used_set.find(nums[i]) != used_set.end())
            {
                continue;
            }
            // 记录这个元素在本层用过了，本层后面不能再用了
            used_set.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        // 由题意，递增子序列中至少有两个元素，所以要从第二个元素开始回溯
        backTracking(nums, 0);
        return result;
    }
};
// @lc code=end
