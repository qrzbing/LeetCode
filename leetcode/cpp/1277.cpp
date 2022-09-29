#include "global.hpp"

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 1)
            {
                sum += 1;
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 1)
            {
                sum += 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    continue;
                matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
