/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 定义边缘
        int top = 0, left = 0;
        int m = matrix.size(), n = matrix[0].size();
        int bottom = m - 1, right = n - 1;
        int count = m * n;
        vector<int> ret;

        while (count > 0)
        {
            // 上
            for (int i = left; i <= right && count > 0; i++)
            {
                ret.push_back(matrix[top][i]);
                count--;
            }
            top++;
            // 右
            for (int i = top; i <= bottom && count > 0; i++)
            {
                ret.push_back(matrix[i][right]);
                count--;
            }
            right--;
            // 下
            for (int i = right; i >= left && count > 0; i--)
            {
                ret.push_back(matrix[bottom][i]);
                count--;
            }
            bottom--;
            // 左
            for (int i = bottom; i >= top && count > 0; i--)
            {
                ret.push_back(matrix[i][left]);
                count--;
            }
            left++;
        }
        return ret;
    }
};
// @lc code=end
