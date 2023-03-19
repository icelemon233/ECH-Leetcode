/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
class Solution
{
public:
    // 枚举法
    // 累加最多10次就会回到最初的状态
    // 轮转最多n次也会回到原来的状态（n为字符串长度）
    // 轮转位数为偶数，累加只对奇数位产生影响
    // 轮转位数为奇数，累加对奇数位、偶数位都产生影响
    // 总结：全部枚举次数为轮转次数×奇数位累加×偶数位累加=n*10*10
    string findLexSmallestString(string s, int a, int b)
    {
        // 字典序可以视为string转换为num，直接用min/max比较
        string ret = s;
        for (int i = 0; i < s.size(); i++)
        {
            // 轮转
            s = s.substr(s.size() - b) + s.substr(0, s.size() - b);
            // 累加
            for (int j = 0; j < 10; j++)
            {
                // 累加对奇数位的影响
                for (int k = 1; k < s.size(); k += 2)
                {
                    s[k] = (s[k] - '0' + a) % 10 + '0';
                }
                // 轮转位数为奇数
                if (b % 2 != 0)
                {
                    for (int x = 0; x < 10; x++)
                    {
                        // 累加对偶数位的影响
                        for (int y = 0; y < s.size(); y += 2)
                        {
                            s[y] = (s[y] - '0' + a) % 10 + '0';
                        }
                        ret = min(ret, s);
                    }
                }
                // 轮转位数为偶数
                else
                {
                    ret = min(ret, s);
                }
            }
        }
        return ret;
    }

    // BFS暴力搜索法
    // string findLexSmallestString(string s, int a, int b)
    // {
    //     // 队列存储所枚举的字符串结果序列
    //     queue<string> que;
    //     // 哈希表存储出现过的字符串
    //     unordered_set<string> set;
    //     que.push(s);
    //     set.emplace(s);

    //     string ret = s;
    //     int n = s.size();
    //     while (!que.empty())
    //     {
    //         s = que.front();
    //         que.pop();
    //         ret = min(ret, s);
    //         // 当前字符串累加一次的情况
    //         string s1 = s;
    //         for (int i = 1; i < s.size(); i += 2)
    //         {
    //             s1[i] = (s1[i] - '0' + a) % 10 + '0';
    //         }
    //         // 当前字符串轮转一次的情况
    //         string s2 = s.substr(s.size() - b) + s.substr(0, s.size() - b);
    //         for (auto &s : {s1, s2})
    //         {
    //             // 如果有没出现过的字符串，放入que
    //             if (!set.count(s))
    //             {
    //                 set.insert(s);
    //                 que.emplace(s);
    //             }
    //         }
    //     }
    //     return ret;
    // }
};
// @lc code=end
