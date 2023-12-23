/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        // 如果s的长度为奇数，一定不符合要求
        if (s.size() % 2 != 0)
        {
            return false;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            // 是左括号的，全部push进去
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (st.empty())
                return false;
            else if (s[i] == ')')
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else
                st.pop();
        }
        return st.empty();

        // 技巧方法：在匹配左括号的时候，右括号先入栈，就只需要比较当前元素和栈顶相不相等就可以了
        // bool isValid(string s)
        // {
        //     if (s.size() % 2 != 0)
        //         return false;
        //     stack<char> st;
        //     for (int i = 0; i < s.size(); i++)
        //     {
        //         if (s[i] == '(')
        //             st.push(')');
        //         else if (s[i] == '{')
        //             st.push('}');
        //         else if (s[i] == '[')
        //             st.push(']');
        //         else if (st.empty() || st.top() != s[i])
        //             return false;
        //         else
        //             st.pop();
        //     }
        //     return st.empty();
        // }
    }
};

// @lc code=end
