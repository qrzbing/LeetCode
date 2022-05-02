#include "global.hpp"

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret = {{1}};
        for (int i = 1; i < numRows; i++)
        {
            vector<int> line(i + 1);
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    line[j] = 1;
                }
                else
                {
                    line[j] = ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
            ret.emplace_back(line);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout_2d_vector(sol.generate(30));
    return 0;
}
