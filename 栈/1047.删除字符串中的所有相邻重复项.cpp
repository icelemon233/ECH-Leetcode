/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (s[i] == st.top())
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        // 栈的特性，现在字符串是反的，记得翻转回来
        reverse(result.begin(), result.end());
        return result;
    }

    // // 最速且最优方法：字符串做栈
    // string removeDuplicates(string S)
    // {
    //     string result;
    //     for (char s : S)
    //     {
    //         if (result.empty() || result.back() != s)
    //         {
    //             result.push_back(s);
    //         }
    //         else
    //         {
    //             result.pop_back();
    //         }
    //     }
    //     return result;
    // }
};
// @lc code=end
