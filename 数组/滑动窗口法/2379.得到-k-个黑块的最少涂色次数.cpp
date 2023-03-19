/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        // 记录每个滑动窗口变化次数
        int change = 0;
        // 最少变化次数
        int ret = INT_MAX;

        // 放入最左边一批0~k-1的字符
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
            {
                change++;
            }
        }
        // 这里要做一次赋值，因为如果k就是长度，需要直接返回ret
        ret = change;

        for (int i = k; i < blocks.size(); i++)
        {
            if (blocks[i - k] != blocks[i])
            {
                if (blocks[i] == 'W')
                {
                    change++;
                }
                else
                {
                    change--;
                }
            }
            ret = min(ret, change);
            // 快速检查
            if (ret == 0)
            {
                return ret;
            }
        }
        return ret;
    }
};
// @lc code=end
