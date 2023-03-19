/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;

        ListNode *fastcur = dummyhead;
        ListNode *slowcur = dummyhead;

        // 让fast走n+1步
        while (n-- && fastcur != NULL)
        {
            fastcur = fastcur->next;
        }
        fastcur = fastcur->next;

        // 让fast指向链表末尾NULL
        while (fastcur != nullptr)
        {
            slowcur = slowcur->next;
            fastcur = fastcur->next;
        }

        // 此时slowcur->next就是要删除的节点，做删除操作
        ListNode *tmp = slowcur->next;
        slowcur->next = slowcur->next->next;
        delete (tmp);

        return dummyhead->next;
    }
};
// @lc code=end
