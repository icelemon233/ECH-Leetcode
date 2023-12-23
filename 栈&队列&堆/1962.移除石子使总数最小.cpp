/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    // // 优先队列法
    // int minStoneSum(vector<int> &piles, int k)
    // {
    //     // 建堆：默认是大顶堆，即最大的元素在堆顶
    //     priority_queue<int> pq(piles.begin(), piles.end());
    //     // 堆顶pop，floor(piles[i] / 2)后再入堆，重复k次
    //     for (int i = 0; i < k; ++i)
    //     {
    //         int top = pq.top();
    //         pq.pop();
    //         top -= floor(top / 2);
    //         pq.push(top);    // 自动优化为大顶堆
    //     }
    //     int result = 0;
    //     while (!pq.empty())
    //     {
    //         result += pq.top();
    //         pq.pop();
    //     }
    //     return result;
    // }

    // 原地建堆法
    int minStoneSum(vector<int> &piles, int k)
    {
        // 原地堆：保证最大值在所给范围的最前面，其他值的位置不确定
        // 本质上piles还是数组，原地堆做了一个特殊sort处理
        make_heap(piles.begin(), piles.end());
        // 数组第一个元素不是0的情况下，-=floor(piles[i] / 2)，重复k次
        // 注意这里不要使用--k，否则会少一次
        while (k-- && piles[0])
        {
            // push_heap：最后一个元素入堆
            // pop_heap：第一个元素与最后一个元素互换，然后前面n-1个值重新make_heap
            pop_heap(piles.begin(), piles.end());
            piles.back() -= floor(piles.back() / 2);
            push_heap(piles.begin(), piles.end());    // 自动优化为大顶堆
        }
        return accumulate(piles.begin(), piles.end(), 0);
    };
};

// @lc code=end
