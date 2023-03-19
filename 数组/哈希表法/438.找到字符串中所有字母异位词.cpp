/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int slen = s.size();
        int plen = p.size();

        if (slen < plen)
        {
            return vector<int>();
        }
        // 通过哈希表存入s当前滑动窗口的字母个数和p的字母个数
        // 哈希表一致，则判定为字母异位词（也可能完全一致）
        vector<int> s_window(26, 0);
        vector<int> p_have(26, 0);
        vector<int> ret;
        for (int i = 0; i < plen; i++)
        {
            s_window[s[i] - 'a']++;
            p_have[p[i] - 'a']++;
        }
        // 首先判断一次
        if (s_window == p_have)
        {
            ret.emplace_back(0);
        }
        // 一直判断到slen - plen，后续长度不足plen就不用看了
        for (int i = 0; i < slen - plen; i++)
        {
            --s_window[s[i] - 'a'];
            ++s_window[s[i + plen] - 'a'];

            if (s_window == p_have)
            {
                ret.emplace_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end
