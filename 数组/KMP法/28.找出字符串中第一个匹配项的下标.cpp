/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
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

    int strStr(string haystack, string needle)
    {
        // 没有给匹配的字符串当然没有结果
        if (needle.size() == 0)
        {
            return 0;
        }

        // 获取next数组
        int next[needle.size()];
        getNext(next, needle);

        // 匹配
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            // 不匹配，检查next数组
            while (j > 0 && needle[j] != haystack[i])
            {
                j = next[j - 1];
            }
            // 两种情况（原理同next数组）
            // 1. 一直到j==0都没有办法找到haystack[i] == needle[j]，直接让j = 0
            // 2. j > 0的时候就找到了haystack[i] == needle[j]，那么j可以++，因为i跟着for也要++，回到正常匹配情况
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                // i已经匹配到haystack的最后一位
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
// @lc code=end
