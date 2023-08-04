/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    // result.push_back(path) 不同位置的写法
    // 写法1
    void backTracking(vector<int> &nums, int startIndex)
    {
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            result.push_back(path);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }
        result.push_back({});
        backTracking(nums, 0);
        return result;
    }

    // 写法2
    // void backTracking(vector<int> &nums, int startIndex)
    // {
    //     result.push_back(path);
    //     for (int i = startIndex; i < nums.size(); i++)
    //     {
    //         path.push_back(nums[i]);
    //         backTracking(nums, i + 1);
    //         path.pop_back();
    //     }
    // }

    // vector<vector<int>> subsets(vector<int> &nums)
    // {
    //     if (nums.size() == 0)
    //     {
    //         return {};
    //     }
    //     backTracking(nums, 0);
    //     return result;
    // }
};
// @lc code=end
