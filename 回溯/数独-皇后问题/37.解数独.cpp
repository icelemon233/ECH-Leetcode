/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
public:
    bool backTracking(vector<vector<char>> &board)
    {
        // 遍历所有'.'的地方就行，不需要终止条件
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char input = '1'; input <= '9'; input++)
                    {
                        if (isValid(input, i, j, board))
                        {
                            board[i][j] = input;
                            if (backTracking(board))
                            {
                                return true;
                            };
                            board[i][j] = '.';
                        }
                    }
                    // 关键点，否则会time limited
                    // 9个数都试完了，都不行，那么就返回false
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(char input, int row, int col, vector<vector<char>> &board)
    {
        // 检查行
        for (int i = 0; i < 9; i++)
        {
            if (input == board[row][i])
            {
                return false;
            }
        }

        // 检查列
        for (int i = 0; i < 9; i++)
        {
            if (input == board[i][col])
            {
                return false;
            }
        }

        // 检查所归属宫格
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (input == board[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backTracking(board);
    }
};
// @lc code=end
