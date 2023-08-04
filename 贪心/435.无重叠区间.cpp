/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int result = 0;
        int rightBorder = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < rightBorder)
            {
                result++;
                rightBorder = min(rightBorder, intervals[i][1]);
                continue;
            }
            rightBorder = intervals[i][1];
        }
        return result;
    }
};
// @lc code=end
