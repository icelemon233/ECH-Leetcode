/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // 维护一个“能跳多远”的变量，并实时更新
        // 如果这个变量能到达最终下标，就可以直接返回
        if (nums.size() == 1)
        {
            return true;
        }
        int jumpMax = 0;
        for (int i = 0; i <= jumpMax; i++)
        {
            jumpMax = max(jumpMax, i + nums[i]);
            if (jumpMax >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
