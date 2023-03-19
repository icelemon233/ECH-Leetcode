/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution
{
public:
    // // 十进制化为二进制
    // int dec2bin(int n)
    // {
    //     // 二进制结果
    //     int sum = 0;
    //     // 10的阶乘, 用于计算十/百/千位等位置是0还是1
    //     int times = 1;
    //     while (n)
    //     {
    //         sum = sum + times * (n % 2);
    //         n /= 2;
    //         times = times * 10;
    //     }
    //     return sum;
    // }

    vector<int> circularPermutation(int n, int start)
    {
        vector<int> ret;
        // 提前申请内存
        ret.reserve(1 << n);
        // 放入初始结果
        ret.push_back(start);
        // 法1：归纳法
        // 从n-1位格雷码到n位格雷码，以0开头的一半已经视为存放于ret中（根据start的不同，也有可能是以1开头）
        // ret中存在的n-1位格雷码序列，倒序执行
        // 1. 与start异或 2. 第n次执行，就与2^n-1或 3. 与start异或
        // 原理：89.格雷编码官方解答方法1
        // 注：异或就是翻转的作用。第二次异或是为了从（以0为开头的格雷码）回到（以start为开头的格雷码）
        for (int i = 1; i <= n; i++)
        {
            // 扩充一半位置
            int size = ret.size();
            // 倒序
            for (int j = size - 1; j >= 0; j--)
            {
                // 三步合一
                ret.emplace_back(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
            }
        }
        return ret;
    }
};
// @lc code=end
