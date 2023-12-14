/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 *
 * [2048] 下一个更大的数值平衡数
 */

// @lc code=start
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isBalance(int x)
    {
        // 计算这个数是否是数值平衡数
        vector<int> count(10);
        while (x > 0)
        {
            count[x % 10]++;
            x /= 10;
        }
        for (int d = 0; d < 10; ++d)
        {
            if (count[d] > 0 && count[d] != d)
            {
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n)
    {
        for (int i = n + 1; i <= 1224444; ++i)
        {
            if (isBalance(i))
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
