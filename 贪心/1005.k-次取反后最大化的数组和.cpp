/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution
{
public:
    // 自定义排序规则函数
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);

        // 1. 负数全部变正数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                k--;
                nums[i] = -nums[i];
            }
            if (k == 0)
            {
                break;
            }
        }

        // 2. 如果还有多余的次数，那么反复转变数值最小的元素，将K用完
        // 剩余k的次数如果为偶数，则直接计算结果（变偶数次等于没变，包括0）
        // 剩余k的次数如果为偶数，则变个符号
        if (k % 2 == 1)
        {
            nums[nums.size() - 1] *= -1;
        }

        // 3. 计算结果
        int result = 0;
        for (int num : nums)
        {
            result += num;
        }
        return result;
    }
};
// @lc code=end
