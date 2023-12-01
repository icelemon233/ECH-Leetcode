/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

// @lc code=start
class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        // 1. 分数和年龄合并成pair进行排序，分数优先排序，同分再排年龄
        int n = scores.size();
        vector<pair<int, int>> people;
        for (int i = 0; i < n; ++i)
        {
            people.push_back({scores[i], ages[i]});
        }
        sort(people.begin(), people.end());

        // 2. dp[i]表示将当前第i个球员纳入球队时最多能取得的分数
        // 由于分数已经排序，所以第i个球员的年龄应该比之前所有球员的年龄要大，否则不能取对应的dp阶段
        vector<int> dp(n, 0);
        int ret = 0;
        // i是当前球员，j是之前的所有球员
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (people[j].second <= people[i].second)
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += people[i].first;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

// @lc code=end
