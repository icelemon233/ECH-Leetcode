/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<string> week = {"Sunday",
                           "Monday",
                           "Tuesday",
                           "Wednesday",
                           "Thursday",
                           "Friday",
                           "Saturday"};

public:
    string dayOfTheWeek(int day, int month, int year)
    {
        // // 1. 蔡勒公式
        // if (month <= 2)
        // {
        //     month += 12;
        //     year--;
        // }
        // int m = month;
        // int y = year % 100;
        // int c = year / 100;
        // int d = day;
        // int w =
        //     ((y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1) % 7 + 7) %
        //     7;
        // return week[w];

        // // 2. 基姆拉尔森公式
        // if (month <= 2)
        // {
        //     month += 12;
        //     year--;
        // }
        // int y = year;
        // int m = month;
        // int d = day;
        // int w =
        //     (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) %
        //     7;
        // return week[w];

        // 3. 根据题意计算
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        // 先以一年365天计算，(year - 1969) / 4 判断输入年是否闰年
        int days = 365 * (year - 1971) + (year - 1969) / 4;
        // 再计算前month-1个月经历了多少天
        for (int i = 0; i < month - 1; ++i)
        {
            days += monthDays[i];
        }
        // 如果是闰年，并且输入月超过3月，那么2月那天需要+1，所以结果直接+1
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) &&
            month >= 3)
        {
            days += 1;
        }
        // 然后直接加上输入日
        days += day;
        // 由于1970年12月31日为星期四，所以如果days是1（也就是1971年1月1日应该是星期五，最终week下标为4，所以days+4
        return week[(days + 4) % 7];
    }
};

// @lc code=end
