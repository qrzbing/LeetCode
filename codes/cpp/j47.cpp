#include "global.hpp"
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        for (int i = 0, j = 1; j < grid[0].size(); j++) //处理第一行
        {
            grid[i][j] += grid[i][j - 1];
        }
        for (int i = 1, j = 0; i < grid.size(); i++) //处理第一列
        {
            grid[i][j] += grid[i - 1][j];
        }
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                grid[i][j] = grid[i][j] + max(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};