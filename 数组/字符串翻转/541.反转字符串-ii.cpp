/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
    // string reverseStr(string s, int k)
    // {
    //     int start = 0;
    //     int end = s.size() - 1;
    //     // 执行前若干组2k个字符
    //     while ((end - start) > 2 * k)
    //     {
    //         int kstart = start;
    //         int kend = start + k - 1;
    //         while (kstart < kend)
    //         {
    //             swap(s[kstart], s[kend]);
    //             kstart++;
    //             kend--;
    //         }
    //         start += 2 * k;
    //     }
    //     if (start > end)
    //     {
    //         return s;
    //     }
    //     else if ((end - start) < k)
    //     {
    //         int kstart = start;
    //         int kend = end;
    //         while (kstart < kend)
    //         {
    //             swap(s[kstart], s[kend]);
    //             kstart++;
    //             kend--;
    //         }
    //         return s;
    //     }
    //     else
    //     {
    //         int kstart = start;
    //         int kend = start + k - 1;
    //         while (kstart < kend)
    //         {
    //             swap(s[kstart], s[kend]);
    //             kstart++;
    //             kend--;
    //         }
    //         return s;
    //     }
    //     return s;
};
// @lc code=end
