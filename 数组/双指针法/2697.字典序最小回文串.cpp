/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 *
 * [2697] 字典序最小回文串
 */

// @lc code=start
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        //双指针法
        int begin = 0, end = s.size() - 1;
        int result = 0;
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                // 用字典序更小的那个
                s[begin] = min(s[begin], s[end]);
                s[end] = s[begin];
            }
            begin++;
            end--;
        }
        return s;
    }
};

// @lc code=end
