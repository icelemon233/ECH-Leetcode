/*
 * @lc app=leetcode.cn id=1255 lang=cpp
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        // 三步走
        // 1. 统计letters种可用字母数量
        // 2. 将words串视为二进制串，那么选取words的情况共有2^words.size()种
        // 3. 针对2中的每种选取情况，通过 &2^1、&2^2、……&2^n操作找出选取哪些words进行计算
        // 注：&2^1、&2^2、……&2^n表示选取words中第一个、第二个、……、第n个word，结果是1证明这个单词被选中，结果是0证明这个单词没有被选中
        // 注2：也可以将2的二进制串执行十进制换二进制操作，找出哪些是1就是选中了哪些word，原理同上

        // 1
        int n = words.size();
        // 最终返回结果
        int ret = 0;

        vector<int> letters_count(26);
        for (auto ch : letters)
        {
            letters_count[ch - 'a']++;
        }
        // 2和3
        for (int s = 1; s < (1 << n); s++)
        {
            // 统计当前二进制串s的情况下选中了哪些word
            vector<int> words_Count(26);
            for (int k = 0; k < n; k++)
            {
                // words[k] 没有被二进制串s选中
                if ((s & (1 << k)) == 0)
                {
                    continue;
                }
                // 选中，则统计字母使用数量
                for (auto ch : words[k])
                {
                    words_Count[ch - 'a']++;
                }
            }

            // 统计当前二进制串s的情况下选中的word是否满足letters要求
            bool is_valid = true; // 判断当前二进制串s是否合法（满足letters要求）
            int sum = 0;          // 保存当前二进制串s所选中的word的得分

            for (int i = 0; i < 26; i++)
            {
                sum += score[i] * words_Count[i];
                is_valid = is_valid && (words_Count[i] <= letters_count[i]);
                // 一旦超过letters要求就会变为false，证明当前二进制串s所选中的word不能满足letters要求，丢弃
                if (is_valid == false)
                {
                    break;
                }
            }
            if (is_valid)
            {
                ret = max(ret, sum);
            }
        }
        return ret;
    }
};
// @lc code=end
