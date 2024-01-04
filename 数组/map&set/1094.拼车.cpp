/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    // 差分+前缀和
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        // 人数变化表，表明在第index个位置
        // n=numOfPassengersChange[index]为正，就是等同于车上又多了n个人
        // n=numOfPassengersChange[index]为负，就是等同于车上又少了n个人
        map<int, int> numOfPassengersChange;
        for (auto &trip : trips)
        {
            numOfPassengersChange[trip[1]] += trip[0];
            numOfPassengersChange[trip[2]] -= trip[0];
        }
        int needSeatsNum = 0;
        for (auto [key, value] : numOfPassengersChange)
        {
            needSeatsNum += value;
            if (needSeatsNum > capacity)
            {
                return false;
            }
        }
        return true;
    }
    // 暴力模拟
    //     bool carPooling(vector<vector<int>> &trips, int capacity)
    //     {
    //         unordered_map<int, int> load;
    //         for (auto &trip : trips)
    //         {
    //             for (int i = trip[1]; i < trip[2]; ++i)
    //             {
    //                 load[i] += trip[0];
    //                 if (load[i] > capacity)
    //                 {
    //                     return false;
    //                 }
    //             }
    //         }
    //         return true;
    //     }
};
// @lc code = end
