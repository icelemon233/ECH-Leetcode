/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> s1_plus_s2;
        for (int &num1 : nums1)
        {
            for (int &num2 : nums2)
            {
                s1_plus_s2[num1 + num2]++;
            }
        }
        // 记录a+b+c+d=0次数
        int count = 0;
        for (int &num3 : nums3)
        {
            for (int &num4 : nums4)
            {
                if (s1_plus_s2.find(-num3 - num4) != s1_plus_s2.end())
                {
                    count += s1_plus_s2[-num3 - num4];
                }
            }
        }
        return count;
    }
};
// @lc code=end
