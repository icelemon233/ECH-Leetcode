/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // 排序
        sort(points.begin(), points.end());
        // 默认第一个气球需要一支箭
        int result = 1;
        int rightBorder = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > rightBorder)
            {
                result++;
                rightBorder = points[i][1];
                continue;
            }
            rightBorder = min(rightBorder, points[i][1]);
        }
        return result;
    }
};
// @lc code=end
