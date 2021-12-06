#include "global.hpp"

class Solution
{
public:
    int m, n;
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size(), n = board[0].size();
        int cnt = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        board[i][j] = '\0';
        bool ret = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return ret;
    }
};