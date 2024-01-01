/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */

// @lc code=start
#include <functional>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxStudents(vector<vector<char>> &seats)
    {
        // 一行查询法：
        // 1. 转换问题：
        // 在第 x 行的座位状态为 xxx 的情况下，前 x-1 行最多可以坐多少个学生
        // 2. 简化问题：
        // 将 #..#.# 转化为字符串 010110（二进制数从右往左读）
        // 3. 简化规则，找规律：
        // 3.1 第 2 ~ x-1 行规律：
        // 假设当前第x行的座位二进制数为s = 0100100，那么1的左上和右上都不能坐，对应s>>1和s<<1，第x-1行的座位二进制数t = a(可用座位二进制数) &~ (s<<1|s>>1)
        // 3.2 第1行规律：
        // 最低位的1（从右往左第一个可用座位）一定可以选，同时左边一个座位设置为0（不可用座位），继续往左边找下一个1
        // 因此，就是在不断找最靠右的1（可用座位），用lowbit方法 x&-x（详见补码知识）
        // 左边一个位置设置为0就是 x<<1 | x (或lb*3)
        int m = seats.size();
        int n = seats[0].size();
        // binaryVaildSeats[i]代表第i行的【可用座位的二进制串】的【十进制数】
        vector<int> binaryVaildSeats(m);

        // 可用座位转化为二进制串
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (seats[i][j] == '.')
                {
                    // 将1向左移动j位，并且用 | 运算符赋值给binaryVaildSeats[i]
                    binaryVaildSeats[i] |= 1 << j;
                }
            }
        }

        // 递归函数
        // 每一行需要保存1 << n个数据（对于一行n个座位，可能的字符串情况有 (1 << n) - 1种），-1 表示没有计算过
        vector<vector<int>> memoryMat(m, vector<int>(1 << n, -1));
        function<int(int, int)> dfs = [&](int row, int binarySeats) -> int {
            int &result = memoryMat[row][binarySeats];    // 注意这里是引用
            // 记忆化搜索：如果之前计算过，直接跳过
            if (result != -1)
            {
                return result;
            }
            // 最后计算第一行的情况
            if (row == 0)
            {
                if (binarySeats == 0)
                {
                    return 0;
                }
                // binarySeats不为0，表示存在lowbit，继续计算
                int lowbit = binarySeats & -binarySeats;
                return dfs(row, binarySeats & ~(lowbit << 1 | lowbit)) + 1;
            }
            // 计算当前行的上一行，这一行就是递归核心，把问题从
            // "在第 x 行的座位状态为 xxx 的情况下，前 x-1 行最多可以坐多少个学生"
            // 缩小到
            // "在第 x-1 行的座位状态为 xxx 的情况下，前 x-2 行最多可以坐多少个学生"
            result = dfs(row - 1, binaryVaildSeats[row - 1]);
            // 枚举 binarySeats 的子集 subSeat
            // x = (x-1) & x
            // 目的：原数从右到左（即二进制数从左到右）找到第一个1（可用座位）
            // 如x=01001000，那么第一次subX为01000000，第二次为00001000
            for (int subSeat = binarySeats; subSeat;
                 subSeat = (subSeat - 1) & binarySeats)
            {
                // x & x>>1 （x<<1也行）
                // 目的：找是否有连续的1
                // 如果结果不为0，证明有连续的1
                if ((subSeat & (subSeat >> 1)) == 0)
                {
                    // 计算row-1行的合法位置二进制串，去掉不能坐人的位置
                    int t = binaryVaildSeats[row - 1] &
                            ~(subSeat << 1 | subSeat >> 1);
                    //__builtin_popcount：返回二进制数中1的个数
                    result = max(result,
                                 dfs(row - 1, t) + __builtin_popcount(subSeat));
                }
            }
            return result;
        };
        // 从最后一行开始递归
        return dfs(m - 1, binaryVaildSeats[m - 1]);
    }
};

// @lc code=end
