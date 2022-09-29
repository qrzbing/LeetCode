#include "global.hpp"

class Solution
{
    bool isWin(vector<string> &board, char ch)
    {
        char cmpStr[4] = {ch, ch, ch, '\0'};
        return board[0] == cmpStr ||
               board[1] == cmpStr ||
               board[2] == cmpStr ||
               (board[0][0] == ch && board[1][0] == ch && board[2][0] == ch) ||
               (board[0][1] == ch && board[1][1] == ch && board[2][1] == ch) ||
               (board[0][2] == ch && board[1][2] == ch && board[2][2] == ch) ||
               (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) ||
               (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch);
    }

public:
    bool validTicTacToe(vector<string> &board)
    {
        int oCount = 0, xCount = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((board[i][j] == 'X'))
                {
                    xCount++;
                }
                if ((board[i][j] == 'O'))
                {
                    oCount++;
                }
            }
        }
        if (xCount != oCount && xCount - 1 != oCount)
        {
            return false;
        }
        if (isWin(board, 'X') && oCount != xCount - 1)
        {
            return false;
        }
        if (isWin(board, 'O') && oCount != xCount)
        {
            return false;
        }
        return true;
    }
};

// ["XOX","O O","XOX"]
// ["XXO","XOX","OXO"]
// xxo
// xox
// oxo