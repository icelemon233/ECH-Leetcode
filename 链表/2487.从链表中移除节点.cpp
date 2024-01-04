/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
#include <stack>
using namespace std;

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *dummyHead = new ListNode();
        while (head != nullptr)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = dummyHead->next;
            dummyHead->next = temp;
        }
        return dummyHead->next;
    }

    ListNode *removeNodes(ListNode *head)
    {
        // 简化题意：让链表成为单调非递增链表

        // 1. 递归
        // 分解为无数个子链表，如果子链表头节点右边的值比头节点大，那么保留右边的值，否则保留头节点的值
        // 因为递归是从最右边的节点开始操作，因此上述操作一定符合题意
        if (head == nullptr)
        {
            return nullptr;
        }
        head->next = removeNodes(head->next);
        if (head->next != nullptr && head->next->val > head->val)
        {
            return head->next;
        }
        else
        {
            return head;
        }

        // // 2. 单调栈
        // // 先全部按次序压入栈
        // // 出栈节点如果大于等于新链表当前节点的值，插入表头，否则丢弃
        // stack<ListNode *> st;
        // while (head != nullptr)
        // {
        //     st.push(head);
        //     head = head->next;
        // }
        // ListNode *newNode = new ListNode();
        // newNode->next = st.top();
        // st.pop();
        // while (!st.empty())
        // {
        //     // 优化：不想新建ListNode *变量可以直接用st.top构建新链表
        //     ListNode *node = st.top();
        //     if (node->val >= newNode->next->val)
        //     {
        //         node->next = newNode->next;
        //         newNode->next = node;
        //     }
        //     st.pop();
        // }
        // return newNode->next;

        // // 3. 反转链表
        // // 先反转整个链表，然后按照“右边只取更大值”这个规则处理
        // // 如例：5-2-13-3-8，反转后变成8-3-13-2-5，删除3,2,5即可
        // head = reverse(head);
        // for (ListNode *p = head; p->next != nullptr;)
        // {
        //     if (p->val > p->next->val)
        //     {
        //         p->next = p->next->next;
        //     }
        //     else
        //     {
        //         p = p->next;
        //     }
        // }
        // return reverse(head);
    }
};

// @lc code=end
