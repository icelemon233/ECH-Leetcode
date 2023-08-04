/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        // 第一个孩子分一颗，后面按照规则走
        vector<int> headRules(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                headRules[i] = headRules[i - 1] + 1;
            }
        }

        // 最后一个孩子分一颗，前面按照规则走
        vector<int> tailRules(n, 1);
        // 注意i>=0
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                tailRules[i] = tailRules[i + 1] + 1;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += max(headRules[i], tailRules[i]);
        }
        return result;
    }
};
// @lc code=end
