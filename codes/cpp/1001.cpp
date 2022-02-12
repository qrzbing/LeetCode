#include "global.hpp"

class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        auto hash_p = [](const pair<int, int> &p) -> size_t
        {
            static hash<long long> hash_ll;
            return hash_ll(p.first + (static_cast<long long>(p.second) << 32));
        };
        unordered_set<pair<int, int>, decltype(hash_p)> points(0, hash_p);
        unordered_map<int, int> row, col, diag, antidiag;
        for (vector<int> &lamp : lamps)
        {
            if (points.count({lamp[0], lamp[1]}) == 0)
            {
                points.insert({lamp[0], lamp[1]});
                row[lamp[0]]++;
                col[lamp[1]]++;
                diag[lamp[0] + lamp[1]]++;
                antidiag[lamp[0] - lamp[1]]++;
            }
        }
        int ql = queries.size();
        vector<int> ret(ql);
        for (int i = 0; i < ql; ++i)
        {
            int r = queries[i][0], c = queries[i][1];
            if (row.count(r) > 0 && row[r] > 0)
            {
                ret[i] = 1;
            }
            else if (col.count(c) > 0 && col[c] > 0)
            {
                ret[i] = 1;
            }
            else if (diag.count(r + c) > 0 && diag[r + c] > 0)
            {
                ret[i] = 1;
            }
            else if (antidiag.count(r - c) > 0 && antidiag[r - c] > 0)
            {
                ret[i] = 1;
            }
            for (int x = r - 1; x <= r + 1; ++x)
            {
                for (int y = c - 1; y <= c + 1; ++y)
                {
                    if (x < 0 || y < 0 || x >= n || y >= n)
                    {
                        continue;
                    }
                    auto p = points.find({x, y});
                    if (p != points.end())
                    {
                        points.erase(p);
                        row[x]--;
                        col[y]--;
                        diag[x + y]--;
                        antidiag[x - y]--;
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;

    return 0;
}
