/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    // map计算各元素出现次数，小顶堆保存前K个高频元素（最小的被pop）
    class myComparison
    {
    public:
        bool operator()(const pair<int, int> &map1, const pair<int, int> &map2)
        {
            return map1.second > map2.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // map
        unordered_map<int, int> map;
        for (int &num : nums)
        {
            map[num]++;
        }

        // 小顶堆（用优先队列实现）
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> prior_queue;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            prior_queue.emplace(*it);
            if (prior_queue.size() > k)
            {
                prior_queue.pop();
            }
        }

        // 小顶堆顺序是从大到小，所以应该倒序返回结果
        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = prior_queue.top().first;
            prior_queue.pop();
        }
        return ret;
    }
};
// @lc code=end
