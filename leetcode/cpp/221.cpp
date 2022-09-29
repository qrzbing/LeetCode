#include "global.hpp"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ret = 0;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                ret = 1;
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == '1')
            {
                dp[0][j] = 1;
                ret = 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    continue;
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                ret = max(ret, dp[i][j]);
                // cout << ret << " " << i << " " << j << endl;
            }
        }
        return ret * ret;
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    vector<vector<char>> v = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    assert(sol.maximalSquare(v) == 4);
    return 0;
}
