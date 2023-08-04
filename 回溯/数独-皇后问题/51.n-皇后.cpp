/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
private:
    vector<vector<string>> result;

public:
    // 以行、列为单位都可以，此处以行遍历举例
    void backTracking(int n, int row, vector<string> chessBoard)
    {
        if (row == n)
        {
            result.push_back(chessBoard);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(n, row, col, chessBoard))
            {
                chessBoard[row][col] = 'Q';
                backTracking(n, row + 1, chessBoard);
                chessBoard[row][col] = '.';
            }
        }
    }

    bool isValid(int n, int row, int col, vector<string> chessBoard)
    {
        // 不需要检查横向，每行只填一次，在回溯函数内执行
        // 每次重新检查都要新建变量，推荐用int
        // 检查纵向
        for (int i = 0; i < row; i++)
        {
            if (chessBoard[i][col] == 'Q')
            {
                return false;
            }
        }

        // 检查斜向的时候，只需要检查上面的，下面的行还没开始填
        // 检查左上斜向
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessBoard[i][j] == 'Q')
            {
                return false;
            }
        }

        // 检查右上斜向
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessBoard[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chessBoard(n, string(n, '.'));
        backTracking(n, 0, chessBoard);
        return result;
    }
};
// @lc code=end
