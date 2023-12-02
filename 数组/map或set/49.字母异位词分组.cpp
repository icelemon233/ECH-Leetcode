/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 把字符串作为key，把拥有该串字符串中相同且数量相等的字母的字符串统一为value
        unordered_map<string, vector<string>> string_list;
        for (string &str : strs)
        {
            // 复制一份，作为string_list里面的key
            string key = str;
            sort(key.begin(), key.end());
            string_list[key].emplace_back(str);
        }

        vector<vector<string>> ret;
        for (auto it = string_list.begin(); it != string_list.end(); it++)
        {
            ret.emplace_back(it->second);
        }
        return ret;
    }
};
// @lc code=end
