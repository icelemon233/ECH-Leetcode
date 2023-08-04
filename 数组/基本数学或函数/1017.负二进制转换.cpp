/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 *
 * [1017] 负二进制转换
 */

// @lc code=start
class Solution
{
public:
    string baseNeg2(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        int k = 1;
        string result;
        while (n)
        {
            if (n % 2)
            {
                result.push_back('1');
                n -= k;
            }
            else
            {
                result.push_back('0');
            }
            k *= -1;
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// @lc code=end
