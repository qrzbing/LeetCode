#include "global.hpp"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
                else if (j == 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else
                {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v;
    v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    assert(sol.minPathSum(v) == 7);
    v = {{1, 2, 3}, {4, 5, 6}};
    assert(sol.minPathSum(v) == 12);

    return 0;
}
