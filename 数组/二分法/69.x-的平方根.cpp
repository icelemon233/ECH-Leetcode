/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int min = 0;
        int max = x;
        if (x == 0 || x == 1)
        {
            return x;
        }
        // 对于平方根结果，二分法查找会停留在min和max之间，所以循环条件这么写，不要写相等
        while (max - min > 1)
        {
            int mid = min + (max - min) / 2;
            if (x / mid < mid)
            {
                max = mid;
            }
            else
            {
                min = mid;
            }
        }
        return min;
    }
};
// @lc code=end
