/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    // static bool compare(vector<int> a, vector<int> b)
    // {
    //     if (a[0] == b[0])
    //     {
    //         return a[1] < b[1];
    //     }
    //     return a[0] < b[0];
    // }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int rightBorder = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= rightBorder)
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
            rightBorder = result.back()[1];
        }
        return result;
    }
};
// @lc code=end
