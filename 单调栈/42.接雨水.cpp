/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{

public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        if (height.size() <= 2)
        {
            return 0;
        }
        int result = 0;
        st.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            // 1. 比前面的柱子小，等待下一个更大的柱子形成凹槽
            if (height[i] < height[st.top()])
            {
                st.push(i);
            }
            // 2. 和前面的柱子相同，替换掉栈里面相同的那个柱子
            else if (height[i] == height[st.top()])
            {
                st.pop();
                st.push(i);
            }
            // 3. 比前面的柱子大，可以开始计算凹槽
            else
            {
                // 3.1 栈不为空，有两种情况
                while (!st.empty() && height[i] > height[st.top()])
                {
                    // 3.1.1 里面只有一个柱子，形成不了凹槽，替换掉这个柱子就好
                    if (st.size() == 1)
                    {
                        st.pop();
                    }
                    // 3.1.2 有两个或以上的柱子，可以形成凹槽，把栈顶两个柱子拉出来计算
                    else
                    {
                        int mid = st.top();
                        st.pop();
                        int left = st.top();
                        int right = i;
                        int h = min(height[left], height[right]) - height[mid];
                        int w = right - left - 1;
                        result += h * w;
                    }
                }
                // 3.2 栈空或者已经计算完本次的凹槽了，把这次的柱子放进栈里
                st.push(i);
            }
        }
        return result;
    }
};
// @lc code=end
