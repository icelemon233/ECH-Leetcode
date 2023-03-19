/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;

        ListNode *cur = dummyhead;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp = cur->next;
            ListNode *nextcur = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = nextcur;
            cur = cur->next->next;
        }
        return dummyhead->next;
    }
};
// @lc code=end
