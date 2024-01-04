/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        unordered_map<int, pair<int, int>> hashmap;
        // 最终遍历过多少个“重复n2次的新s2“
        int traversalS2 = 0;
        int len1 = s1.size();
        int len2 = s2.size();
        // index1和index2是扩展长度后的新s1和新s2下标
        int index1 = 0;
        int index2 = 0;
        // 遍历n1个s1，index最大就是n*len
        while (index1 / len1 < n1)
        {
            // 刚好遍历完一个s1
            if (index1 % len1 == len1 - 1)
            {
                // count：判断k-v的k是否存在v
                if (hashmap.count(index2 % len2))
                {
                    // 计算有规律的循环长度
                    // 距离上次匹配过s2[index2 % len2]这个字符，s1经历了多少位
                    int cycleLen1 = index1 - hashmap[index2 % len2].first;
                    // 距离上次匹配过s2[index2 % len2]这个字符，s2经历了多少位
                    int cycleLen2 = index2 - hashmap[index2 % len2].second;
                    //每个循环有几个s1
                    int cycleS1Count = cycleLen1 / len1;
                    //每个循环有几个s2
                    int cycleS2Count = cycleLen2 / len2;
                    // 计算有几个循环，并直接跳到循环结束
                    // 因为只有刚好又一次遍历s1结束并且是第二次匹配到s2[index2 % len2]这个字符才会到这里计算循环次数，因此一定会多出一个s1，计算的时候要减去最前面的一个s1
                    int cycle = (n1 - 1 - index1 / len1) / cycleS1Count;
                    traversalS2 += cycle * cycleS2Count;
                    index1 += cycle * cycleLen1;
                }
                // hashmap存储的是当前匹配的情况，当s1遍历到index1位置时，s2最终匹配到的位置时index2
                else
                {
                    hashmap[index2 % len2].first = index1;
                    hashmap[index2 % len2].second = index2;
                }
            }
            // 当前s1的第index1 % len1位是否与s2的第index2 % len2位相同
            // 如果相同，并且s2已经刚好循环一遍，那么重复次数加1，index2也++，重新回到s2的第一位
            if (s1[index1 % len1] == s2[index2 % len2])
            {
                if (index2 % len2 == len2 - 1)
                {
                    traversalS2++;
                }
                index2++;
            }
            // 查看s1的下一位
            index1++;
        }
        return traversalS2 / n2;
    }
};

// @lc code=end
