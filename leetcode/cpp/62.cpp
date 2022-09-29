#include "global.hpp"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 初始化值为 1
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    assert(sol.uniquePaths(3, 7) == 28);
    assert(sol.uniquePaths(3, 2) == 3);
    return 0;
}
