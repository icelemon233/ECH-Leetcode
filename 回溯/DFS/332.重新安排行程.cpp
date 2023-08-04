/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution
{
private:
    // 包含所有机票的行程表，必须定义为全局变量
    unordered_map<string, map<string, int>> schedule;
    int ticketNums = 0;

public:
    // 深度搜索+回溯
    // 主要思路：用一个unordered_map存储一个key-value结构
    // key：存放出发机场
    // value：存放到达机场+可飞行次数
    // 由于到达机场要按照字典序排列，所以value不能用哈希表的unordered_map而是红黑树的map
    // 回溯检查出发机场，深度搜索每次可以去到的最远的地方
    // 由于每张机票都需要使用，那么只要机场遍历数量达到票数+1，就证明机票全部使用完毕
    // 由于找到就要直接返回，所以不能设置类型为void
    bool backTracking(vector<string> &result)
    {
        if (result.size() == ticketNums + 1)
        {
            return true;
        }
        // result[result.size()-1]代表result的最后一个元素
        // schedule[result[result.size()-1]]代表找到schedule中以result最后一个元素为出发机场的行程
        for (pair<const string, int> &ticket : schedule[result[result.size() - 1]])
        {
            // 还有飞的次数
            if (ticket.second > 0)
            {
                result.push_back(ticket.first);
                ticket.second--;
                if (backTracking(result))
                {
                    return true;
                }
                result.pop_back();
                ticket.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {

        for (const vector<string> &ticket : tickets)
        {
            // ticket[0]代表出发机场，ticket[1]代表到达机场
            schedule[ticket[0]][ticket[1]]++;
        }
        vector<string> result;
        result.push_back("JFK"); // 起始机场
        ticketNums = tickets.size();
        backTracking(result);
        return result;
    }
};
// @lc code=end
