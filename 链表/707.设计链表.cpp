/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    // 定义链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList()
    {
        // 虚拟头结点
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index)
    {
        if (index > (_size - 1) || index < 0)
        {
            return -1;
        }
        LinkedNode *cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *cur = _dummyHead;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        LinkedNode *newNode = new LinkedNode(val);
        cur->next = newNode;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > _size)
        {
            return;
        }
        if (index < 0)
        {
            index = 0;
        }
        LinkedNode *cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0)
        {
            return;
        }
        LinkedNode *cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete (tmp);
        _size--;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
