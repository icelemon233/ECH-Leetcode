/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    // // 剩余点数法
    // // 转换为求sum减去中间的n-k张卡牌点数，同样能得到前后所选k张牌的最大点数
    // int maxScore(vector<int> &cardPoints, int k)
    // {
    //     int n = cardPoints.size();
    //     // 滑动窗口大小为 n-k
    //     int windowSize = n - k;
    //     // 选前 n-k 个作为初始值
    //     int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
    //     int minPoint = sum;
    //     for (int i = windowSize; i < n; ++i)
    //     {
    //         // 滑动窗口每向右移动一格，增加从右侧进入窗口的元素值，并减少从左侧离开窗口的元素值
    //         sum += cardPoints[i] - cardPoints[i - windowSize];
    //         minPoint = min(minPoint, sum);
    //     }
    //     return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minPoint;
    // }
    // 前缀和法
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        // 计算前缀和和反前缀和
        vector<int> prefix(n + 1, 0);
        vector<int> reversePrefix(n + 1, 0);
        prefix[1] = cardPoints[0];
        reversePrefix[1] = cardPoints[n - 1];
        for (int i = 2; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + cardPoints[i - 1];
            reversePrefix[i] = reversePrefix[i - 1] + cardPoints[n - i];
        }
        // 计算两边前缀和得分
        int maxPoint = 0;
        for (int i = 0; i <= k; ++i)
        {
            maxPoint = max(maxPoint, prefix[i] + reversePrefix[k - i]);
        }
        return maxPoint;
    }
};
// @lc code=end
