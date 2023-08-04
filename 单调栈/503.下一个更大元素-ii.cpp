/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // 对比496.下一个更大元素-i，数组是同一个，改成了循环数组，多了第二次遍历的操作
        stack<int> st;
        vector<int> result(nums.size(), -1);
        for (int i = 0; i < nums.size() * 2; i++)
        {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()])
            {
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return result;
    }
};
// @lc code=end
