#include "global.hpp"

class Solution
{
    int m, n, orig_color;
    vector<pair<int, int>> edge;
    bool atEdge(vector<vector<int>> &grid, int row, int col)
    {
        if (row - 1 < 0 || col - 1 < 0 || row + 1 >= m || col + 1 >= n ||
            grid[row - 1][col] != orig_color ||
            grid[row + 1][col] != orig_color ||
            grid[row][col - 1] != orig_color ||
            grid[row][col + 1] != orig_color)
            return true;
        return false;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col)
    {
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col])
            return;
        visited[row][col] = true;
        if (grid[row][col] != orig_color)
            return;
        if (atEdge(grid, row, col))
            edge.emplace_back(pair<int, int>(row, col));
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row, col - 1);
        dfs(grid, visited, row, col + 1);
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        m = grid.size(), n = grid[0].size(), orig_color = grid[row][col];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, visited, row, col);
        for (pair<int, int> &point : edge)
            grid[point.first][point.second] = color;
        return grid;
    }
};

void cout_vector(vector<vector<int>> &grid)
{
    for (vector<int> &line : grid)
    {
        for (int num : line)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
}

int main()
{

    Solution sol;
    vector<vector<int>> grid = {{1, 1}, {1, 2}};
    // sol.colorBorder(grid, 0, 0, 3);
    // cout_vector(grid);
    grid = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    sol.colorBorder(grid, 2, 2, 3);
    cout_vector(grid);
}