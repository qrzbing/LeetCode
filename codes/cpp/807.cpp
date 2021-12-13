#include "global.hpp"

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> row(n, 0), col(n, 0);
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                row[i] = max(row[i], grid[i][j]);
                col[i] = max(col[i], grid[j][i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ret += min(row[i], col[j]) - grid[i][j];
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    cout << sol.maxIncreaseKeepingSkyline(grid) << "\n";
}