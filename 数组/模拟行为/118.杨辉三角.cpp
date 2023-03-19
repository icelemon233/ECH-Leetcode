/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;
        ret.emplace_back(vector<int>{1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> nowRow;
            nowRow.push_back(1);
            int count = 1;
            while (count < i)
            {
                nowRow.push_back(ret[i - 1][count] + ret[i - 1][count - 1]);
                count++;
            }
            nowRow.push_back(1);
            ret.emplace_back(nowRow);
        }
        return ret;
    }
};
// @lc code=end
