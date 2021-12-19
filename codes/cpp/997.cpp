#include "global.hpp"

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        for (vector<int> &arc : trust)
        {
            inDegree[arc[1] - 1]++;
            outDegree[arc[0] - 1]++;
        }
        for (int i = 0; i < n; ++i)
        {
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
            {
                return i + 1;
            }
        }
        return -1;
    }
};