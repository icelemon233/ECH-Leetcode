/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // map保存 元素-对应下一个最大元素，倒序检查nums2
        // 1. 如果栈为空，入栈
        // 2. 栈不为空，检查是否比栈顶小
        // 3. 如果小于栈顶元素，设置对应下一个最大元素为栈顶元素，再入栈
        // 4. 如果大于等于栈顶元素，一直出栈直到小于栈顶元素或栈空，设置对应下一个最大元素为栈顶元素，再入栈
        unordered_map<int, int> hashmap;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            while (!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }
            hashmap[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            result.push_back(hashmap[nums1[i]]);
        }
        return result;
    }
};
// @lc code=end
