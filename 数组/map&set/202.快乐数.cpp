/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }
        // 类似模拟行为题目，主要思想是用set检测重复情况
        unordered_set<int> loop_set;
        int temp = n;
        while (1)
        {
            int sum = 0;
            while (temp > 0)
            {
                sum += pow(temp % 10, 2);
                temp /= 10;
            }
            if (sum == 1)
            {
                return true;
            }
            else
            {
                if (loop_set.find(sum) != loop_set.end())
                {
                    return false;
                }
                else
                {
                    loop_set.emplace(sum);
                    temp = sum;
                }
            }
        }
    }
};
// @lc code=end
