/*
 * @lc app=leetcode.cn id=2661 lang=cpp
 *
 * [2661] 找出叠涂元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        // 保存从1-n的坐标
        unordered_map<int, pair<int, int>> coor;
        // 保存行、列被涂色个数的数组
        vector<int> rowColored(m, 0);
        vector<int> colColored(n, 0);
        // 遍历矩阵，记录坐标到哈希表中
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                coor[mat[i][j]] = {i, j};
            }
        }
        // 遍历数组，涂色格子对应行列+1，如果行满或列满则返回
        for (int i = 0; i < arr.size(); i++)
        {
            // 注意
            // m行n列，行需要满足n个，列需要满足m个
            if (++rowColored[coor[arr[i]].first] == n || ++colColored[coor[arr[i]].second] == m)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
