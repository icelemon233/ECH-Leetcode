/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */

// @lc code=start
class Solution
{
public:
    int commonFactors(int a, int b)
    {
        // 法1
        //  1. 如果x是a的一个因子，那么x/a!=x的情况下，a/x也是a的一个因子
        //  2. 所以检测范围从1开始，不超过min(a,b)
        int c = min(a, b);
        int result = 0;
        for (int i = 1; i <= c; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                result++;
            }
        }
        return result;

        // 法2：a和b的最大公约数的因子，也一定是a和b的公因子
        // int c = gcd(a, b);
        // int result = 0;
        // for (int i = 1; i * i <= c; i++)
        // {
        //     if (c % i == 0)
        //     {
        //         result++;
        //         if (i * i != c)
        //         {
        //             result++;
        //         }
        //     }
        // }
        // return result;
    }
};
// @lc code=end
