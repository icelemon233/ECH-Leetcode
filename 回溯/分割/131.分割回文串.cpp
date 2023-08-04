/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
private:
    vector<vector<string>> result;
    vector<string> path;

public:
    bool isPalindrome(const string &s, int startIndex, int endIndex)
    {
        for (int i = startIndex, j = endIndex; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    // 从不同的的位置切割
    void backTracking(const string &s, int startIndex)
    {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }

        // 分割线就是startIndex
        for (int i = startIndex; i < s.size(); i++)
        {
            // 以startIndex~i为下标的子串如果是回文子串，则加入到path中
            if (isPalindrome(s, startIndex, i))
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            // 如果不是则直接跳过，加上后续字符检查是否为回文子串
            else
            {
                continue;
            }
            // 寻找下一分割线子串
            backTracking(s, i + 1);
            // 回溯过程，弹出本次已经填在的子串
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        backTracking(s, 0);
        return result;
    }
};
// @lc code=end
