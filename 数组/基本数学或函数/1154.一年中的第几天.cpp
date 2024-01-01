/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
#include <numeric>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int dayOfYear(string date)
    {
        vector<int> monthDays = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day = atoi(date.substr(8, 2).c_str());
        // 闰年
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            monthDays[1] = 29;
        }
        return accumulate(monthDays.begin(), monthDays.begin() + month - 1, 0) +
               day;
        // return day;
    }
};

// @lc code=end
