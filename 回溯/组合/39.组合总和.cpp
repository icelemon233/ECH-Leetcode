/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backTracking(vector<int> &candidates, int sum, int target, int startIndex)
    {
        if (sum > target)
        {
            return;
        }
        else if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backTracking(candidates, sum, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // 为了防止结果重复，需要对candidates进行排序
        // 且回溯递归时要注意下标
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, 0, target, 0);
        return result;
    }
};
// @lc code=end
