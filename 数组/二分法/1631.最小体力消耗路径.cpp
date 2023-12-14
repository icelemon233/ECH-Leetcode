/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // 二分查找法：
        // 针对题目的高度差 1 <= heights[i][j] <= 10^6，用二分判定当前mid（比如刚开始的mid就是999999/2）是否能构建出一条从左上角到右下角的路
        // 如果可以，那么就试试更小的x；如果不行，那么就试试更大的x
        // 目的：为了减少最终的搜索次数
        int rows = heights.size();
        int cols = heights[0].size();
        int result = 0;
        // 开始二分查找
        int left = 0, right = 999999;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 建立路线图，是否已经走过该点
            // 对于不同的x，都要重新建立一次路线图
            vector<vector<int>> isArrived(rows, vector<int>(cols, 0));
            isArrived[0][0] = 1;
            // 广度优先搜索从左上角到右下角的路，用队列保存下一次能够走的点
            queue<pair<int, int>> q;
            // 放入左上角点
            q.emplace(0, 0);    // 等价于q.push({0,0})
            while (!q.empty())
            {
                // pop出当前点
                pair<int, int> point = q.front();
                q.pop();
                // 搜索四个方向哪些点符合要求
                for (int i = 0; i < 4; ++i)
                {
                    int nx = point.first + dirs[i][0];
                    int ny = point.second + dirs[i][1];
                    // 条件1：不超出地图边界
                    // 条件2：没走过这个点
                    // 条件3：绝对值小于mid
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                        !isArrived[nx][ny] &&
                        abs(heights[point.first][point.second] -
                            heights[nx][ny]) <= mid)
                    {
                        q.emplace(nx, ny);
                        isArrived[nx][ny] = 1;
                    }
                }
            }
            // 对于x的路径已经搜索完毕
            // 如果isArrived[rows - 1][cols - 1]是1，证明已经到达右下角点，试试更小的x
            // 否则，证明无法到达右下角点，试试更大的x
            if (isArrived[rows - 1][cols - 1] == 1)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        // 最后返回result就是答案
        return result;
    }
};

// @lc code=end
