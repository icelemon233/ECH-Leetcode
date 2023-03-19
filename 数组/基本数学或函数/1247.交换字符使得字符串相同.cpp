/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        // 2种情况
        // s1与s2长度相同，对称看
        // 计算同一位置不同的有多少对
        // 根据lc结论，s1和s2能匹配的情况下
        // 只会出现 s1、s2均为 奇数个x+奇数个y 或 偶数个x+偶数个y 的情况
        // 偶数个x+偶数个y：不同对两两交换，刚好是 (x+y)/2
        // 奇数个x+奇数个y：做1次s1和s2的xy交换，回到偶数个x+偶数个y的情况
        int x = 0;
        int y = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'x')
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
        }
        // 奇数，不可能匹配，返回-1
        // 偶数，根据上面结论直接得结果
        // 偶数结果(x+y)/2 奇数结果 (x+y)/2+1
        // 能统一写成(x+1)/2+(y+1)/2原因：int
        return (x + y) % 2 == 1 ? -1 : (x + 1) / 2 + (y + 1) / 2;

        // // 同等于
        // if ((x + y) % 2 == 1)
        // {
        //     return -1;
        // }
        // else
        // {
        //     if (x % 2 == 0)
        //     {
        //         return (x + y) / 2;
        //     }
        //     else
        //     {
        //         return (x + y) / 2 + 1;
        //     }
        // }
    }
};
// @lc code=end
