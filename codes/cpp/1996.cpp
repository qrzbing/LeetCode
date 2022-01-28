#include "global.hpp"

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        int ret = 0;
        int maxDefence = 0;
        sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int> &b)
             { return (a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]); });
        for (vector<int> &p : properties)
        {
            if (p[1] < maxDefence)
            {
                ret++;
            }
            else
            {
                maxDefence = p[1];
            }
        }
        return ret;
    }
};