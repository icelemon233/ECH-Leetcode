/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
private:
    // 映射表
    unordered_map<int, string> phoneMap = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    vector<string> result;

public:
    void backTracking(string digits, string nowString, int index)
    {
        if (nowString.size() == digits.size())
        {
            result.push_back(nowString);
            return;
        }
        int phoneNumber = digits[index] - '0';
        string numMap = phoneMap[phoneNumber];
        for (int i = 0; i < numMap.size(); i++)
        {
            nowString.push_back(numMap[i]);
            backTracking(digits, nowString, index + 1);
            nowString.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return {};
        }
        backTracking(digits, "", 0);
        return result;
    }
};
// @lc code=end
