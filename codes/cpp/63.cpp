#include "global.hpp"

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = obstacleGrid[0][0] == 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (i == 0)
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else if (j == 0)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v;
    v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    assert(sol.uniquePathsWithObstacles(v) == 2);
    v = {{0, 1}, {0, 0}};
    assert(sol.uniquePathsWithObstacles(v) == 1);
    v = {{1, 0}};
    assert(sol.uniquePathsWithObstacles(v) == 0);
    return 0;
}
