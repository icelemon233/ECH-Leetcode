/*
 * @lc app=leetcode.cn id=2276 lang=cpp
 *
 * [2276] 统计区间中的整数数目
 */

// @lc code=start
#include <algorithm>
#include <map>
using namespace std;

class CountIntervals
{
    // 方法1：珂朵莉树

private:
    map<int, int> m;
    int cnt = 0;    // 所有区间长度和

public:
    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        // 遍历所有被 [left,right] 覆盖到的区间（部分覆盖也算）
        for (auto it = m.lower_bound(left); it != m.end() && it->second <= right; m.erase(it++))
        {
            int l = it->second, r = it->first;
            // 合并后的新区间，其左端点为所有被覆盖的区间的左端点的最小值
            left = min(left, l);
            // 合并后的新区间，其右端点为所有被覆盖的区间的右端点的最大值
            right = max(right, r);
            cnt -= r - l + 1;
        }
        cnt += right - left + 1;
        // 所有被覆盖到的区间与 [left,right] 合并成一个新区间
        m[right] = left;
    }

    int count()
    {
        return cnt;
    }

    //方法2：动态开点线段树

    // private:
    //     CountIntervals *left = nullptr, *right = nullptr;
    //     int l, r, cnt = 0;

    // public:
    //     CountIntervals() : l(1), r(1e9)
    //     {
    //     }

    //     CountIntervals(int l, int r) : l(l), r(r)
    //     {
    //     }

    //     void add(int L, int R)
    //     {    // 为方便区分变量名，将递归中始终不变的入参改为大写（视作常量）
    //         if (cnt == r - l + 1)
    //             return;    // 当前节点已被完整覆盖，无需执行任何操作
    //         if (L <= l && r <= R)
    //         {    // 当前节点已被区间 [L,R] 完整覆盖，不再继续递归
    //             cnt = r - l + 1;
    //             return;
    //         }
    //         int mid = (l + r) / 2;
    //         if (left == nullptr)
    //             left = new CountIntervals(l, mid);    // 动态开点
    //         if (right == nullptr)
    //             right = new CountIntervals(mid + 1, r);    // 动态开点
    //         if (L <= mid)
    //             left->add(L, R);
    //         if (mid < R)
    //             right->add(L, R);
    //         cnt = left->cnt + right->cnt;
    //     }

    //     int count()
    //     {
    //         return cnt;
    //     }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end
