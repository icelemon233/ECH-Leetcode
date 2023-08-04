/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // 对n-1个数+1 等效于 对1个数-1
        int minNum = *min_element(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums)
        {
            result += num - minNum;
        }
        return result;
    }
};
// @lc code=end
