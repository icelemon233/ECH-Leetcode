/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */

// @lc code=start
class Solution
{
public:
    // 公式法
    // 如果正方形土地的右上角坐标为(n,n)，即边长为2n，周长为8n，那么其中包含的苹果总数为 2n(n+1)(n+1)
    // 提示：还可以用二分去找2*mid(mid+1)(mid+1)是否大于neededApples（此处不再详细写）
    long long minimumPerimeter(long long neededApples)
    {
        long long n = 1;
        for (; 2 * n * (n + 1) * (2 * n + 1) < neededApples; ++n)
            ;
        return n * 8;
    }
};

// @lc code=end
