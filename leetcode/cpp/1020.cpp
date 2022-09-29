#include "global.hpp"

class Solution
{
    int m, n;
    void dfs(vector<vector<int>> &grid, int x, int y, int num)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
        {
            return;
        }
        // cout_2d_vector(grid);
        grid[x][y] = 2;
        dfs(grid, x - 1, y, num);
        dfs(grid, x + 1, y, num);
        dfs(grid, x, y - 1, num);
        dfs(grid, x, y + 1, num);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            dfs(grid, i, 0, 2);
            dfs(grid, i, n - 1, 2);
        }
        for (int j = 0; j < n; ++j)
        {
            dfs(grid, 0, j, 2);
            dfs(grid, m - 1, j, 2);
        }
        int ret = 0;
        for (int i = 1; i < m - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ret += 1;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    cout << sol.numEnclaves(v) << endl;
    return 0;
}
