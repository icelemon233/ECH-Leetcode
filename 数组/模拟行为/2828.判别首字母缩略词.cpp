/*
 * @lc app=leetcode.cn id=2828 lang=cpp
 *
 * [2828] 判别首字母缩略词
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        if (s.size() != words.size())
        {
            return false;
        }
        int index = 0;
        for (auto word: words)
        {
            if (word[0] != s[index])
            {
                return false;
            }
            index++;
        }
        return true;
    }
};

// @lc code=end
