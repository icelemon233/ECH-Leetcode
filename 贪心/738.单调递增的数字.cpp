/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // 标记法
        // 1.从后往前遍历，如果当前位比前一位小，此位标记为false，同时前面位数字-1
        // 2.被标记为false的位后面全部标记为‘9’，也就是说只需要记录最前面的false位
        string str = to_string(n);
        int flagLoc = INT_MAX;
        for (int i = str.size() - 1; i > 0; i--)
        {
            if (str[i] < str[i - 1])
            {
                flagLoc = i;
                str[i - 1]--;
            }
        }

        for (int i = flagLoc; i < str.size(); i++)
        {
            str[i] = '9';
        }

        return stoi(str);
    }
};
// @lc code=end
