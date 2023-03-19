/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 虚拟头结点法，之后的题目统一使用虚拟头结点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete (tmp);
            }
            else
            {
                cur = cur->next;
            }
        }
        // 和原始头结点不同，使用虚拟头结点后，需要做一步返回真正的头结点
        head = dummyHead->next;
        delete dummyHead;
        return head;
        // 不主动释放内存，以上等价于 return dummyHead->next

        // //原始头结点法
        // // 首先检查头结点，如果是val就一直删
        // while (head != NULL && head->val == val)
        // {
        //     ListNode *tmp = head;
        //     head = head->next;
        //     delete (tmp);
        // }

        // // 检查剩余节点
        // // 注1：最后要返回头结点，这里新建一个结点代替头结点进行传递
        // // 注2：由于头结点已经检查，所以接下来检查的都是下一个结点的值
        // ListNode *cur = head;
        // while (cur != NULL && cur->next != NULL)
        // {
        //     if (cur->next->val == val)
        //     {
        //         ListNode *tmp = cur->next;
        //         cur->next = cur->next->next;
        //         delete (tmp);
        //     }
        //     else
        //     {
        //         cur = cur->next;
        //     }
        // }
        // return head;
    }
};
// @lc code=end
