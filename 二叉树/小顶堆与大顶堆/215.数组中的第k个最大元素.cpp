/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
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

    int findKthLargest(vector<int> &nums, int k)
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

        // 小顶堆顺序是从大到小，所以倒序返回最后一个结果
        for (int i = prior_queue.size() - k + 1; i > 0; i--)
        {
            prior_queue.pop();
        }
        return prior_queue.top().first;
    }
};
// @lc code=end
