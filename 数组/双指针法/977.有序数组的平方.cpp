/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

//@lc code = start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int minindex = 0;
        int maxindex = nums.size() - 1;
        int decount = nums.size();
        // 提前申请nums.size()空间的数组
        vector<int> res(decount);
        // 规则：
        // 有序数组平方之后，规律是中间小两边大
        // 从两边开始，谁大就挑出来放最后
        while (decount > 0)
        {
            if (nums[minindex] * nums[minindex] <= nums[maxindex] * nums[maxindex])
            {
                res[decount - 1] = nums[maxindex] * nums[maxindex];
                maxindex--;
            }
            else
            {
                res[decount - 1] = nums[minindex] * nums[minindex];
                minindex++;
            }
            decount--;
        }
        return res;
    }
};

// @lc code=end
