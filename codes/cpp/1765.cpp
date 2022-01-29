#include "global.hpp"

class Solution
{

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> bfs_queue;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                {
                    bfs_queue.emplace(i, j);
                    height[i][j] = 0;
                }
            }
        }
        while (!bfs_queue.empty())
        {
            pair<int, int> &top = bfs_queue.front();
            for (int(&dir)[2] : dirs)
            {
                int x = top.first + dir[0], y = top.second + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && height[x][y] == -1)
                {
                    height[x][y] = height[top.first][top.second] + 1;
                    bfs_queue.emplace(x, y);
                }
            }
            bfs_queue.pop();
        }
        return height;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> test = {
        {0, 1},
        {0, 0}};
    cout_2d_vector(sol.highestPeak(test));
}