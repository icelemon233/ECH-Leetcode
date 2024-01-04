/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

// @lc code=start
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int &num : nums)
        {
            if (num % 2 == 0)
            {
                map[num]++;
            }
        }

        int maxValue = 0;
        int result = -1;
        for (auto keyValue : map)
        {
            // unordered_map无序，所以还需要判断当出现次数相同时，key的值是不是更小（题目要求返回更小的那个）
            if (result == -1 || keyValue.second > maxValue || keyValue.second == maxValue && result > keyValue.first)
            {
                maxValue = keyValue.second;
                result = keyValue.first;
            }
        }
        return result;
    }
};
// @lc code=end
