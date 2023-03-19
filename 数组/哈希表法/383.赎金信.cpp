/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        vector<int> table(26);

        // table存入magazine里面每个字母出现的次数
        for (auto &ch : magazine)
        {
            table[ch - 'a']++;
        }

        // 如果有某个字母次数被用完，说明不符合题意
        for (auto &ch : ransomNote)
        {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
