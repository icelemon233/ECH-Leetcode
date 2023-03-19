/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // 存放数字的栈
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            // 规则：如果此次遇到字符，数字栈一定有值，所以均在遇到字符的时候执行操作
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(num2 + num1);
                if (tokens[i] == "-")
                    st.push(num2 - num1);
                if (tokens[i] == "*")
                    st.push(num2 * num1);
                if (tokens[i] == "/")
                    st.push(num2 / num1);
            }
            else
            // stoll()：字符串转int函数
            {
                st.push(stoll(tokens[i]));
            }
        }
        return st.top();
    }
};
// @lc code=end
