/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    //     // 暴力
    // public:

    //     vector<int> nextLargerNodes(ListNode *head)
    //     {
    //         ListNode *tmp = head;
    //         vector<int> result;
    //         while (tmp != nullptr)
    //         {
    //             int nextLargerVal = 0;
    //             ListNode *cur = tmp;
    //             while (cur->next != nullptr)
    //             {
    //                 if (cur->next->val > tmp->val)
    //                 {
    //                     nextLargerVal = cur->next->val;
    //                     break;
    //                 }
    //                 else
    //                 {
    //                     cur = cur->next;
    //                 }
    //             }
    //             result.push_back(nextLargerVal);
    //             tmp = tmp->next;
    //         }
    //         return result;
    //     }

    // 单调栈方法
    // 从最后的节点开始，那就递归遍历到最后再开始进行单调栈操作
private:
    stack<int> st;
    vector<int> result;

public:
    void traversal(ListNode *node)
    {
        if (node->next == nullptr)
        {
            result.push_back(0);
            st.push(node->val);
            return;
        }
        traversal(node->next);
        if (!st.empty())
        {
            if (node->val < st.top())
            {
                result.push_back(st.top());
                st.push(node->val);
            }
            else
            {
                while (!st.empty() && node->val >= st.top())
                {
                    st.pop();
                }
                result.push_back(st.empty() ? 0 : st.top());
                st.push(node->val);
            }
        }
        else
        {
            result.push_back(0);
        }
    }

    vector<int> nextLargerNodes(ListNode *head)
    {
        traversal(head);
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
