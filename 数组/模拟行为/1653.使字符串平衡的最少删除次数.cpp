/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        // 第一次：找出字符串中有多少个'a'
        int count_a = 0;
        for (char &ch : s)
        {
            if (ch == 'a')
            {
                count_a++;
            }
        }
        if (count_a == 0)
        {
            return 0;
        }
        // 定义为'a'的数量，这一步很重要
        int ret = count_a;
        // 第二次：依次遍历
        // 原理：左边必须全是a，右边必须全是b
        // 是'a'则少删一次
        // 是'b'则多删一次
        for (char &ch : s)
        {
            if (ch == 'a')
            {
                count_a--;
            }
            else
            {
                count_a++;
            }
            ret = min(ret, count_a);
        }
        return ret;
    }
};
// @lc code=end
