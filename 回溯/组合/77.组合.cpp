/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
public:
    void backTracking(int n, int k, int startIndex)
    {
        // 剪枝：path 长度加上区间 [startIndex, n] 的长度小于 k，那么就不可能构造出长度为 k 的 path
        if (path.size() + (n - startIndex + 1) < k)
        {
            return;
        }
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backTracking(n, k, 1);
        return result;
    }
};
// @lc code=end
