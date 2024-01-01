/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int roundScores(vector<int> player)
    {
        int scores = 0;
        int playTimes = player.size();
        for (int i = 0; i < playTimes; ++i)
        {
            // 如果是第二轮，只需要第一轮是10就有翻倍得分
            if ((i > 0 && player[i - 1] == 10) ||
                (i > 1 && player[i - 2] == 10))
            {
                scores += 2 * player[i];
            }
            else
            {
                scores += player[i];
            }
        }
        return scores;
    }

    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int player1Scores = roundScores(player1);
        int player2Scores = roundScores(player2);
        // 输出胜负
        return player1Scores == player2Scores  ? 0
               : player1Scores > player2Scores ? 1
                                               : 2;
    }
};

// @lc code=end
