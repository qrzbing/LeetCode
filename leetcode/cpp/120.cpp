#include "global.hpp"

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == i)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }
        return *min_element(triangle[m - 1].begin(), triangle[m - 1].end());
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    vector<vector<int>> v;
    v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    assert(sol.minimumTotal(v) == 11);
    v = {{-10}};
    assert(sol.minimumTotal(v) == -10);
    return 0;
}
