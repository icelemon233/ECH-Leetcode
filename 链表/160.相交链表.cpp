/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 主要思想：如果链A和链B相交，那么一定是同时结束的，就可以把末尾进行对齐

        // 先求各链表长度
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL)
        { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL)
        { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }

        // 求完长度记得回去！
        curA = headA;
        curB = headB;

        // 无论什么情况，都让链A成为最长的链
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--)
        {
            curA = curA->next;
        }

        // 遍历剩余的节点，相同则返回
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
// @lc code=end
