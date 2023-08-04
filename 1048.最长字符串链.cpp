/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int result = 0;
        // 字符串排序
        sort(words.begin(), words.end(), [&](string a, string b)
             { return a.size() < b.size(); });
        // 建立哈希表，作为dp查询表
        unordered_map<string, int> map;
        for (string &word : words)
        {
            map[word] = 1;
            // wordA是wordB的前身：wordA的任何地方添加恰好一个字母使其变成wordB
            // 反之，wordB删除任意一个字母后存在一个wordA对应也可以定义wordA是wordB的前身
            // 遍历words，把每个word都当做wordB看待，再去哈希表内查询最长链
            for (int i = 0; i < word.size(); i++)
            {
                string newWord = word;
                auto it = map.find(newWord.erase(i, 1));
                if (it != map.end() && it->second > 0)
                {
                    map[word] = max(map[word], it->second + 1);
                }
            }
            result = max(result, map[word]);
        }
        return result;
    }
};
// @lc code=end
