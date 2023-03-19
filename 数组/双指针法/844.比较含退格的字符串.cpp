/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int ssize = s.size() - 1;
        int tsize = t.size() - 1;
        int s_backspace_count = 0;
        int t_backspace_count = 0;
        // 因为可能很快就会遍历完其中一个字符串，但最终他们两是有可能相等的，需要对每一个字符串都完全遍历
        while (ssize >= 0 || tsize >= 0)
        {
            // 找s的字符，如果该字符串遍历完ssize会是-1，下同理
            while (ssize >= 0)
            {
                // 记录退格次数
                if (s[ssize] == '#')
                {
                    s_backspace_count++;
                    ssize--;
                }
                else
                {
                    // 还是要退格删除，继续找
                    if (s_backspace_count > 0)
                    {
                        s_backspace_count--;
                        ssize--;
                    }
                    // 这时候已经找到一个合法字符了
                    else
                    {
                        break;
                    }
                }
            }

            // 找t的字符
            while (tsize >= 0)
            {
                // 记录退格次数
                if (t[tsize] == '#')
                {
                    t_backspace_count++;
                    tsize--;
                }
                else
                {
                    // 还是要退格删除，继续找
                    if (t_backspace_count > 0)
                    {
                        t_backspace_count--;
                        tsize--;
                    }
                    // 这时候已经找到一个合法字符了
                    else
                    {
                        break;
                    }
                }
            }

            // 对比一下两个字符，首先要看是不是已经超出范围了
            // 如果没超出范围，看看这两个字符是否相等
            if (ssize >= 0 && tsize >= 0)
            {
                if (s[ssize] != t[tsize])
                {
                    return false;
                }
            }
            // 如果ssize和tsize有一个超出范围，证明有一个已经搜索完了，那么存在以下两种情况
            //  1. ssize和tsize有一个大于0，证明大于0的字符串非空，另一个小于0的字符串是空的，这两字符串一定不一样
            //  2. 都小于0，那么这两都是空的字符串，大的while循环会退出，直接返回true
            else
            {
                if (ssize >= 0 || tsize >= 0)
                {
                    return false;
                }
            }
            // 都没有返回false，那就继续往前面查
            ssize--;
            tsize--;
        }
        return true;
    }
};
// @lc code=end
