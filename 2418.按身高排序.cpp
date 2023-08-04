/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 *
 * [2418] 按身高排序
 */

// @lc code=start
class Solution
{
public:
    // 法1：下标分组法
    // vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    // {
    //     vector<string> result;
    //     int n = names.size();
    //     vector<int> index(n);
    //     iota(index.begin(), index.end(), 0);
    //     sort(index.begin(), index.end(), [&](int i, int j)
    //          { return heights[i] > heights[j]; });
    //     for (int &idx : index)
    //     {
    //         result.push_back(names[idx]);
    //     }
    //     return result;
    // }

    // 法2：捆绑分组法（将需要排序的数组和下标捆绑在一起）
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<string> result;
        int n = names.size();
        vector<pair<int, int>> pairVec;
        for (int i = 0; i < n; i++)
        {
            pairVec.emplace_back(heights[i], i);
        }
        sort(pairVec.begin(), pairVec.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });
        for (int i = 0; i < n; i++)
        {
            result.push_back(names[pairVec[i].second]);
        }
        return result;
    }
};
// @lc code=end
