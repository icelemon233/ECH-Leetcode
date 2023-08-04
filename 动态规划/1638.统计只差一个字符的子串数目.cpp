/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */

// @lc code=start
class Solution
{
public:
    // 暴力遍历法
    // int countSubstrings(string s, string t)
    // {
    //     int result = 0;
    //     // i为s遍历下标
    //     // j为t遍历下标
    //     // k为子串长度
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         for (int j = 0; j < t.size(); j++)
    //         {
    //             int diff = 0;
    //             for (int k = 0; i + k < s.size() && j + k < t.size(); k++)
    //             {
    //                 // 计算下标为i~i+k的s子串与j~j+k的t子串差别diff
    //                 // diff=0 -> continue
    //                 // diff=1 -> result+1
    //                 // diff>1 -> break
    //                 diff += s[i + k] == t[j + k] ? 0 : 1;
    //                 if (diff == 1)
    //                 {
    //                     result++;
    //                 }
    //                 else if (diff > 1)
    //                 {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }

    // 动态规划
    // 待注释
public:
    int countSubstrings(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dpl(m + 1, vector<int>(n + 1));
        vector<vector<int>> dpr(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dpl[i + 1][j + 1] = s[i] == t[j] ? (dpl[i][j] + 1) : 0;
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dpr[i][j] = s[i] == t[j] ? (dpr[i + 1][j + 1] + 1) : 0;
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i] != t[j])
                {
                    ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
                }
            }
        }
        return result;
    }
};
// @lc code=end
