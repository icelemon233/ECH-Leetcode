/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
    void remove_redundant_blank(string &s)
    {
        int slow = 0;
        int fast = 0;
        while (fast < s.size())
        {
            if (s[fast] != ' ')
            {
                // slow不为0则不是第一个单词，加一个空格
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                // slow和fast一直右移，到出现下一个空格
                while (fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
            fast++;
        }
        s.resize(slow);
    }

    void swap_part(string &s)
    {
        int slow = 0;
        int fast = 0;
        // 注意这里留多一位，因为要处理fast - 1
        while (fast <= s.size())
        {
            if (fast == s.size() || s[fast] == ' ')
            {
                reverse(s, slow, fast - 1);
                slow = ++fast;
            }
            else
            {
                ++fast;
            }
        }
    }

    string reverseWords(string s)
    {
        // 三步走
        // 1.去空格
        // 2.翻转字符
        // 3.翻转单词
        remove_redundant_blank(s);
        reverse(s, 0, s.size() - 1);
        swap_part(s);
        return s;
    }
};
// @lc code=end
