/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 长度不一样，判定不是“字母异位词”
        if (s.length() != t.length())
        {
            return false;
        }

        // 字母表最多有26个字母
        vector<int> table(26, 0);
        // 字符串s的每个字母放入table
        // -‘a’是为了从字母表开始数刚好是从0开始数
        for (auto &ch : s)
        {
            table[ch - 'a']++;
        }
        for (auto &ch : t)
        {
            table[ch - 'a']--;
            // 一旦减至小于0或者说t中出现了一个不属于s的字符
            // 一定会出现table[ch - 'a'] < 0
            // 立即判定不是“字母异位词”
            if (table[ch - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
