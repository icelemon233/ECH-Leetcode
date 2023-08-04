/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]] = i;
        }

        vector<int> result;
        int preFarLoc = -1;
        int resetLoc = 0;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]] = max(map[s[i]], preFarLoc);
            if (map[s[i]] == i)
            {
                result.push_back(resetLoc + 1);
                // 后面还有一次resetLoc++，所以这里要设置为-1
                resetLoc = -1;
            }
            preFarLoc = map[s[i]];
            resetLoc++;
        }

        return result;
    }
};
// @lc code=end
