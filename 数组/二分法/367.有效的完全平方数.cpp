/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // 一个很有意思的数学算法
        // 原理:(n+1)^2-n^2=2n+1
        int num1 = 1;
        while (num > 0)
        {
            num -= num1;
            num1 += 2;
        }
        return num == 0;
    }

    // bool isPerfectSquare(int num)
    // {
    //     int left = 0, right = num;
    //     while (left <= right)
    //     {
    //         int mid = left + (right - left) / 2;
    //         // INT_MAX是2^31-1，唯一溢出的情况是INT_MAX除以2再相乘
    //         long square = (long)mid * mid;
    //         if (square < num)
    //         {
    //             left = mid + 1;
    //         }
    //         else if (square > num)
    //         {
    //             right = mid - 1;
    //         }
    //         else
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};
// @lc code=end
