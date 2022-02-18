#include "global.hpp"

class Solution
{
    vector<vector<int>> dirs = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int step = 0; step <= k; ++step)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (step == 0)
                    {
                        dp[step][i][j] = 1;
                    }
                    else
                    {
                        for (vector<int> &dir : dirs)
                        {
                            int di = i + dir[0], dj = j + dir[1];
                            if (di >= 0 && di < n && dj >= 0 && dj < n)
                            {
                                dp[step][i][j] += dp[step - 1][di][dj] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};

int main()
{
    Solution sol;

    return 0;
}
