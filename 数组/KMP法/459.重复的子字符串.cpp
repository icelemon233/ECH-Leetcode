/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    // next数组
    void getNext(int *next, const string &s)
    {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            // j要保证大于0，因为下面有取j-1作为数组下标的操作
            while (j > 0 && s[i] != s[j])
            {
                // 倒退回当前j位置再前一个的next，直到找到s[i] == s[j]或j==0
                j = next[j - 1];
            }
            // 两种情况
            // 1. 一直到j==0都没有办法找到s[i] == s[j]，直接让next[i] = j = 0
            // 2. j > 0的时候就找到了s[i] == s[j]，让这个j指向下一个，匹配的时候就是用j前一个
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
        {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        // 理解KMP算法在本题的作用：实例
        // 原字符串 ：  a  s  d  f a s d f a s d f
        // next数组： -1 -1 -1 -1 0 1 2 3 4 5 6 7
        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
