/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // 分析
        //  1. prediff(nums[i] - nums[i-1]) 和 curdiff(nums[i+1] - nums[i])满足正负摆动关系要求
        //  2. 如果某个数重复数次而又恰好是波动顶点，只能保留一个，则当(preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)才记录，curDiff=0不记录
        //  3. 按照2的条件，当序列为1-2-2-2-3的时候，1和最后一个2都会被记录。所以当满足2的条件时，才更新preDiff，这样就能避免记录不是最值点的极值点
        //  4. 少于两个元素的序列也是摆动序列。按照1-3的条件，最后一个点（最后一个i+1下标的点）不会被记录，所以最终记录的是波动线的数量，而点的数量总会多1，所以最终结果要加1
        int preDiff = 0;
        int curDiff = 0;
        int result = 1;
        // 注意遍历到nums.size()-1而不是nums.size()，否则下标越界但不会报错
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
            {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end
