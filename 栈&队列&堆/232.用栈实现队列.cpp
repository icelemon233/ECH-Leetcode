/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    // 将队列结构  想象为   两个栈结构
    // ————————         ——————||———————
    // ————————         ——————||———————
    stack<int> stack_in;
    stack<int> stack_out;
    MyQueue()
    {
    }

    void push(int x)
    {
        stack_in.push(x);
    }

    int pop()
    {
        if (stack_out.empty())
        {
            while (!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        // 需要返回被pop的元素
        int top = stack_out.top();
        stack_out.pop();
        return top;
    }

    int peek()
    {
        int ret = this->pop();
        stack_out.push(ret);
        return ret;
    }

    bool empty()
    {
        return stack_in.empty() && stack_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
