/*
 * @lc app=leetcode.cn id=2454 lang=cpp
 *
 * [2454] 下一个更大元素 IV
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        // 游戏规则
        // 设置两个单调栈，分别为胜者组和败者组
        // 对于每位选手，先进败者组，从最后（最小）一直向前挑战
        // 如果当前选手胜利，胜者组对手将掉到败者组，败者组对手将出局，例A战胜了B，那么即宣告选手A最终输给了选手B（A的后续第二大整数就是B）
        // 如果当前选手失败，回到胜者组末尾
        // upper和lower保存的都是下标
        vector<int> upper;
        vector<int> lower;
        vector<int> result(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i)
        {
            // 败者组挑战
            while (!lower.empty() && nums[i] > nums[lower.back()])
            {
                // 输出第二大整数
                result[lower.back()] = nums[i];
                // 败者组出局
                lower.pop_back();
            }
            // 胜者组挑战
            // 由于需要记录下标，在这里用下标遍历更好，需要记录位置并重新resize胜者组
            int pos = upper.size() - 1;
            // 这里不能用upper.empty()判断了，因为遍历完才会进行统一删除，只能用pos判断
            while (pos >= 0 && nums[i] > nums[upper[pos]])
            {
                --pos;
            }
            // 胜者组掉到败者组（统一操作）
            lower.insert(lower.end(), upper.begin() + (pos + 1), upper.end());
            // 结束，回到胜者组末尾
            upper.resize(pos + 1);
            upper.push_back(i);
        }
        return result;
    }
};

// @lc code=end
