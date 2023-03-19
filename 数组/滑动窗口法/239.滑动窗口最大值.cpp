/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
private:
    class doubleSideQueue
    {
    public:
        // 双端队列保存滑动窗口最大值与“可能”的极大值，这是一条单调队列
        deque<int> dq;

        // 定义需要用到的几个函数
        // 1.pop 单调队列前段弹出
        void pop(int value)
        {
            if (!dq.empty() && value == dq.front())
            {
                dq.pop_front();
            }
        }
        // 2.push 单调栈后端进入
        void push(int value)
        {
            while (!dq.empty() && value > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(value);
        }
        // 3.队列前端的值front（最大值）
        int front()
        {
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 主要思想：欺软怕硬，队列中的比我大的全部干掉，直到遇到大哥
        doubleSideQueue myqueue;
        vector<int> ret;
        // 先执行第一个滑动窗口
        for (int i = 0; i < k; i++)
        {
            myqueue.push(nums[i]);
        }
        ret.emplace_back(myqueue.front());
        // 开始遍历数组
        for (int i = k; i < nums.size(); i++)
        {
            myqueue.pop(nums[i - k]);
            myqueue.push(nums[i]);
            ret.emplace_back(myqueue.front());
        }
        return ret;
    }
};
// @lc code=end
