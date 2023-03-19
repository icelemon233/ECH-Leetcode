/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> ret(n, vector<int>(n, 0));
        // 定义边缘
        int top = 0, left = 0;
        int bottom = n - 1, right = n - 1;
        int count = 1;

        while (count <= n * n)
        {
            // 上
            for (int i = left; i <= right && (count <= n * n); i++)
            {
                ret[top][i] = count;
                count++;
            }
            top++;
            // 右
            for (int i = top; i <= bottom && (count <= n * n); i++)
            {
                ret[i][right] = count;
                count++;
            }
            right--;
            // 下
            for (int i = right; i >= left && (count <= n * n); i--)
            {
                ret[bottom][i] = count;
                count++;
            }
            bottom--;
            // 左
            for (int i = bottom; i >= top && (count <= n * n); i--)
            {
                ret[i][left] = count;
                count++;
            }
            left++;
        }
        return ret;
    }
};
// @lc code=end
