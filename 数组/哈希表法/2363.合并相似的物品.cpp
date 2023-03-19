/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> item_map;

        for (vector<int> &item : items1)
        {
            item_map[item[0]] += item[1];
        }
        for (vector<int> &item : items2)
        {
            item_map[item[0]] += item[1];
        }

        vector<vector<int>> ret;
        for (auto &[value, weight] : item_map)
        {
            ret.emplace_back(vector<int>{value, weight});
        }

        return ret;
    }
};
// @lc code=end
