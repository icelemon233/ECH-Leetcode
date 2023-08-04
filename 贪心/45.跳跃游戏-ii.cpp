/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int result = 0;
        int nextJump = 0;
        int canJumpMax = 0;
        // 思路
        // 假设本轮可以从下标0跳到下标3(nextJump)
        // 那么遍历下标0/1/2的时候，实时更新可以跳到的最大距离canJumpMax
        // 当遍历到下标3的时候，再更新下标3可以跳到的最大距离canJumpMax
        // 那么此时就可以知道下标0-3任意一个位置可以跳到的最大距离canJumpMax
        // 将下一次更新点定在这个canJumpMax

        // 注意i只遍历到nums.size() - 1
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 每一个下标都更新取最大
            canJumpMax = max(nums[i] + i, canJumpMax);
            // 到达更新点，把下一个更新点定义为前一批下标可以跳到的最大距离更新一下
            if (i == nextJump)
            {
                nextJump = canJumpMax;
                // 优化剪枝，当终点就是最后nums.size() - 1时，就直接跳出去，记得跳到终点的这一次也加上
                if (nextJump == nums.size() - 1)
                {
                    return ++result;
                }
                else
                {
                    result++;
                }
            }
        }
        return result;
    }
};
// @lc code=end
