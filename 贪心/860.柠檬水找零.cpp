/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fiveDollars = 0;
        int tenDollars = 0;
        // int twentyDollars = 0;

        for (int i = 0; i < bills.size(); i++)
        {

            if (bills[i] == 5)
            {
                fiveDollars++;
            }
            else if (bills[i] == 10)
            {
                tenDollars++;
                if (fiveDollars <= 0)
                {
                    return false;
                }
                fiveDollars--;
            }
            else
            {
                if (tenDollars >= 1 && fiveDollars >= 1)
                {
                    tenDollars--;
                    fiveDollars--;
                }
                else if (fiveDollars >= 3)
                {
                    fiveDollars -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
