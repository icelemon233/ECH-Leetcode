/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 快慢指针法
        // 此处不涉及头结点相关操作，直接用head而不是dummyHead避免复杂
        ListNode *slowcur = head;
        ListNode *fastcur = head;

        // fast每次走两步，slow每次走一步
        // 如果有环，在slow进环的第一周内一定会遇到slow=fast，证明见代码随想录
        // 注意这里的循环条件，fast是一次走两步的
        while (fastcur != NULL && fastcur->next != NULL)
        {
            slowcur = slowcur->next;
            fastcur = fastcur->next->next;
            if (slowcur == fastcur)
            {
                // 找到相遇处后，在链表头和相遇处各新建一个节点指针，均为一步走，相遇时一定是环入口，证明见代码随想录
                ListNode *index1 = head;
                ListNode *index2 = slowcur;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                // 返回index1和index2均可
                return index1;
            }
        }
        return NULL;
    }
};
// @lc code=end
