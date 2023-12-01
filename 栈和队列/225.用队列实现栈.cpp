/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
    // 两个队列结构
public:
    queue<int> queue1;
    queue<int> queue2; // 保存"top"元素之外的其他元素，再赋值给“主栈”queue1
    MyStack()
    {
    }

    void push(int x)
    {
        queue1.push(x);
    }

    int pop()
    {
        int size = queue1.size();
        while (size > 1)
        {
            queue2.push(queue1.front());
            queue1.pop();
            size--;
        }
        int top = queue1.front();
        // 先赋值再清空，不要搞错了
        queue1 = queue2;
        while (!queue2.empty())
        {
            queue2.pop();
        }
        return top;
    }

    int top()
    {
        return queue1.back();
    }

    bool empty()
    {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
