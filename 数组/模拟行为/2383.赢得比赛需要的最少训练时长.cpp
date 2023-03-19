/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int trainTime = 0;
        // 精力
        for (int i = 0; i < energy.size(); i++)
        {
            trainTime += energy[i];
        }
        trainTime = initialEnergy > trainTime ? 0 : trainTime + 1 - initialEnergy;
        // 经验
        int exNeed = 0;                // 需要训练的经验
        int exNow = initialExperience; // 当前经验
        for (int i = 0; i < experience.size(); i++)
        {
            if (exNow > experience[i])
            {
                exNow += experience[i];
            }
            else
            {
                // 本次需要训练的经验
                int train_ex = experience[i] - exNow + 1;
                exNeed += train_ex;
                exNow += train_ex + experience[i];
            }
        }
        trainTime += exNeed;
        return trainTime;
    }
};
// @lc code=end
