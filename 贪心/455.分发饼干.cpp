/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int result = 0;

        // 贪心匹配
        for (int i = 0, j = 0; i < s.size() && j < g.size(); j++)
        {
            if (s[i] >= g[j])
            {
                i++;
                result++;
            }
            else
            {
                continue;
            }
        }
        return result;
    }
};
// @lc code=end
