/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            // 对后面重复的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backTracking(candidates, sum, target, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // 为了防止结果重复，需要对candidates进行排序
        // 且回溯递归时要注意下标
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, 0, target, 0);
        return result;
    }
};
// @lc code=end
