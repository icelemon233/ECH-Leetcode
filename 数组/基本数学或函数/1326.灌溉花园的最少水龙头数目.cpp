/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        // rightMost记录的是ranges中任意元素
        // 以下标i作为起点，值rightMost[i]为终点
        // 以此保存ranges中所有覆盖过的距离
        vector<int> rightMost(n + 1);
        iota(rightMost.begin(), rightMost.end(), 0);

        for (int i = 0; i <= n; ++i)
        {
            // 灌溉区域为[i - ranges[i], i + ranges[i]]
            // 下标（最左端）小于0就设置为0
            // 值（最右端）大于n就设置为n
            int index = max(0, i - ranges[i]);
            int value = min(n, i + ranges[i]);
            rightMost[index] = value;
        }

        // 遍历
        int last = 0;
        int pre = 0;
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            last = max(last, rightMost[i]);
            // 从0开始也覆盖不到全部
            if (i == last)
            {
                return -1;
            }
            if (i == pre)
            {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};
// @lc code=end
