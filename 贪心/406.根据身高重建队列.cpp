/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), compare);
        int n = people.size();
        // 此处用list更优
        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++)
        {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};
// @lc code=end
