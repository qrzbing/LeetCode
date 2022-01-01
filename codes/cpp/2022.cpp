#include "global.hpp"

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int size = original.size();
        if (size != m * n)
            return {};
        vector<vector<int>> ret;
        for (int i = 0; i < m; ++i)
        {
            vector<int> line;
            for (int j = 0; j < n; ++j)
            {
                int curr = i * n + j;
                if (curr >= size)
                {
                    if (!line.empty())
                        ret.emplace_back(line);
                    goto here;
                }
                // cout << original[curr] << "\n";
                line.emplace_back(original[curr]);
            }
            ret.emplace_back(line);
        }
    here:
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> vec;
    vec = {1, 1, 1, 1};
    cout_2d_vector(sol.construct2DArray(vec, 4, 1));
}