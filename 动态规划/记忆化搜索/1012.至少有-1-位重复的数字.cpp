/*
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */

// @lc code=start
class Solution
{
    // 需要用到的全局变量
private:
    vector<vector<int>> dp;

public:
    int memorySearch(string s, int i, int mask, bool isLimited, bool isNum)
    {
        // mask 大小为 1024，长度为 10 位，记录 0 - 9 选择的情况，若 i 已选择，则 mask 中第 i 位为 1
        // 结束条件：如果 isNum 为 false，表示一直没有选择，直接返回 0；否则返回 1
        // 如果到结束条件时，isNum 仍为 false，还有一种表示含义，即表示 0
        if (i == s.size())
        {
            return isNum ? 1 : 0;
        }

        // isNum 同 isLimit，需要特判一下
        if (!isLimited && isNum && dp[i][mask] != -1)
        {
            return dp[i][mask];
        }

        // 上届和下界
        int down = isNum ? 0 : 1;
        int up = isLimited ? s[i] - '0' : 9;
        // f(i + 1, mask, false, false) 表示仍然不选择
        int res = isNum ? 0 : memorySearch(s, i + 1, mask, false, false);
        // 这里记录当每一位选择down-up之间数字时
        // 符合要求的num记录在res中
        for (int d = down; d <= up; d++)
        {
            // 如果 d 没有选择过
            if (((mask >> d) & 1) == 0)
            {
                res += memorySearch(s, i + 1, mask | (1 << d), isLimited && d == up, true);
            }
        }
        if (!isLimited && isNum)
        {
            dp[i][mask] = res;
        }
        return res;
    }
    int numDupDigitsAtMostN(int n)
    {
        // 转化为求1位重复的数字都没有，再用n减去
        // 转换为字符串
        string str = to_string(n);
        int len = str.size();
        dp.resize(len, vector<int>(1 << 10, -1));
        return n - memorySearch(str, 0, 0, true, false);
    }
};
// @lc code=end
