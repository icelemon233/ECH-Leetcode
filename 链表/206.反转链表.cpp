/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
public:
    // 双指针法
    ListNode *reverseList(ListNode *head)
    {
        // 这道题的dummyHead就是pre，为简便此处只写pre
        ListNode *tmp;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // // 递归法
    // ListNode *reverse(ListNode *pre, ListNode *cur)
    // {
    //     if (cur == NULL)
    //     {
    //         return pre;
    //     }
    //     ListNode *tmp = cur->next;
    //     cur->next = pre;
    //     return reverse(cur, tmp);
    // }

    // ListNode *reverseList(ListNode *head)
    // {
    //     return reverse(NULL, head);
    // }
};
// @lc code=end
