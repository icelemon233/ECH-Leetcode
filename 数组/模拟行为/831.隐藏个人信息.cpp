/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class Solution
{
public:
    string maskPII(string s)
    {
        string result = "";
        // 判断是电话号码还是邮箱
        if (s.find('@') != s.npos)
        {
            // 邮箱
            int aPos = s.find('@');
            result += tolower(s[0]);
            result += "*****";
            for (int i = aPos - 1; i < s.size(); i++)
            {
                result += tolower(s[i]);
            }
        }
        else
        {
            // 电话号码
            string phoneNumber = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    phoneNumber += s[i];
                }
            }
            if (phoneNumber.size() == 10)
            {
                result += "***-***-";
            }
            else if (phoneNumber.size() == 11)
            {
                result += "+*-***-***-";
            }
            else if (phoneNumber.size() == 12)
            {
                result += "+**-***-***-";
            }
            else if (phoneNumber.size() == 13)
            {
                result += "+***-***-***-";
            }
            for (int i = phoneNumber.size() - 4; i < phoneNumber.size(); i++)
            {
                result += phoneNumber[i];
            }
        }
        return result;
    }
};

// @lc code=end
