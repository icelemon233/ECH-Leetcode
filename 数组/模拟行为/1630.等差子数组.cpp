/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

// @lc code=start
class Solution
{
public:
    // 排序法
    bool checkIfArithmetic(vector<int> &nums, int left, int right)
    {
        vector<int> subVec;
        for (int i = left; i <= right; i++)
        {
            subVec.push_back(nums[i]);
        }
        sort(subVec.begin(), subVec.end());
        int diff = subVec[1] - subVec[0];
        for (int i = 2; i < subVec.size(); i++)
        {
            int nowDiff = subVec[i] - subVec[i - 1];
            if (nowDiff != diff)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ret;
        for (int i = 0; i < l.size(); i++)
        {
            ret.push_back(checkIfArithmetic(nums, l[i], r[i]));
        }
        return ret;
    }
};
// @lc code=end
