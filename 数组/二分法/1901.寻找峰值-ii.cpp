/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int getMaxNumOfCurrentRow(vector<int> &a)
    {
        return max_element(a.begin(), a.end()) - a.begin();
    }

    // 利用“人往高处走”的原理，对于某个坐标点(i,j)
    // 如果第i行最大值比(i,j)下面的那个相邻数字小，那么峰值一定在下面的行
    // 如果第i行最大值比(i,j)下面的那个相邻数字大，那么峰值一定在上面的行，或者是峰值本身
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        // right必须设置为-2，否则检测下一行的操作会造成越界
        int left = 0, right = m - 2;
        while (left <= right)
        {
            int mid_i = left + (right - left) / 2;
            int mid_j = getMaxNumOfCurrentRow(mat[mid_i]);
            // 如果第i行最大值比(i,j)下面的那个相邻数字小
            if (mat[mid_i][mid_j] < mat[mid_i + 1][mid_j])
            {
                left = mid_i + 1;
            }
            // 如果第i行最大值比(i,j)下面的那个相邻数字大
            else
            {
                right = mid_i - 1;
            }
        }
        return {left, getMaxNumOfCurrentRow(mat[left])};
    }
};

// @lc code=end
