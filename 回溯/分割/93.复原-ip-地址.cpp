/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
private:
    vector<string> result;
    string path;

public:
    bool isValid(const string &s, int startIndex, int endIndex)
    {
        if (startIndex > endIndex)
        {
            return false;
        }
        // 0开头的数字不合法
        if (s[startIndex] == '0' && startIndex != endIndex)
        {
            return false;
        }
        int num = 0;
        for (int i = startIndex; i <= endIndex; i++)
        {
            // 题目示意s仅由数字组成，所以这里可写可不写
            // 遇到非数字字符不合法
            // if (s[i] > '9' || s[i] < '0')
            // {
            //     return false;
            // }
            num = num * 10 + (s[i] - '0');
            // 如果超过255就可以直接返回false了
            // 这里不加判断条件会报错，num超出int范围
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }

    void backTracking(string &s, int startIndex, int pointNum = 0)
    {
        if (pointNum == 3)
        {
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            // 以startIndex~i为下标的子串如果是回文子串，则加入到path中
            if (isValid(s, startIndex, i))
            {
                // 加点
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                // 注意插入逗号之后要往右多走一步
                backTracking(s, i + 2, pointNum);
                // 把点去掉
                s.erase(s.begin() + i + 1);
                pointNum--;
            }
            // 如果一开头就不合法，可以加上下一个字符重新计算
            else
            {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
        {
            return {};
        }
        else
        {
            backTracking(s, 0);
            return result;
        }
    }
};
// @lc code=end
