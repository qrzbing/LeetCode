#include "global.hpp"

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            int x = i, y = 0;
            bool flag = true;
            for (; y < m; y++)
            {
                if (grid[y][x] == 1)
                {
                    if (x + 1 < n && grid[y][x + 1] == 1)
                    {
                        x++;
                    }
                    else
                    {
                        flag = false;
                        ret.emplace_back(-1);
                        break;
                    }
                }
                else
                {
                    if (x - 1 >= 0 && grid[y][x - 1] == -1)
                    {
                        x--;
                    }
                    else
                    {
                        flag = false;
                        ret.emplace_back(-1);
                        break;
                    }
                }
            }
            if (flag)
                ret.emplace_back(x);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> vvi;
    vvi = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    cout_vector(sol.findBall(vvi));
    vvi = {{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}};
    cout_vector(sol.findBall(vvi));
    vvi = {{-1}};
    cout_vector(sol.findBall(vvi));
    return 0;
}
