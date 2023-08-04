/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

public:
    void backTracking(int len, int target, int sum, int startIndex)
    {
        // 剪枝：如果和已经大于target，都可以不考虑了
        if (sum > target)
        {
            return;
        }

        if (path.size() == len)
        {
            if (sum == target)
            {
                result.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backTracking(len, target, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // 只使用数字1到9，每个数字最多使用一次，先排除不可能的结果
        int minValidN = 0;
        int maxValidN = 0;
        for (int i = 1; i <= k; i++)
        {
            minValidN += i;
            maxValidN += n - i + 1;
        }
        if (n < minValidN || n > maxValidN)
        {
            return {};
        }

        // 回溯
        backTracking(k, n, 0, 1);
        return result;
    }
};
// @lc code=end
