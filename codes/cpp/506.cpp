#include "global.hpp"
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<pair<int, int>> vpii;
        vector<string> ans(n);
        string desc[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        for (int i = 0; i < n; ++i)
        {
            // vpii.push_back(make_pair(-score[i], i)); // before c++11
            vpii.emplace_back(make_pair(-score.at(i), i)); // after c++11
        }
        sort(vpii.begin(), vpii.end());
        for (int i = 0; i < n; ++i)
        {
            if (i >= 3)
            {
                ans.at(vpii.at(i).second) = to_string(i + 1);
            }
            else
            {
                ans.at(vpii.at(i).second) = desc[i];
            }
        }
        return ans;
    }
};