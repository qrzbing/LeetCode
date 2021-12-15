#include "global.hpp"
class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<int> ret(n, -1);
        vector<vector<int>> graph(n);
        for (vector<int> &rich : richer)
        {
            graph.at(rich.at(1)).emplace_back(rich.at(0));
        }
        function<void(int)> dfs = [&](int x)
        {
            if (ret[x] != -1)
                return;
            ret[x] = x;
            for (int y : graph[x])
            {
                dfs(y);
                if (quiet[ret[y]] < quiet[ret[x]])
                {
                    ret[x] = ret[y];
                }
            }
        };
        for (int i = 0; i < n; ++i)
        {
            dfs(i);
        }
        return ret;
    }
};