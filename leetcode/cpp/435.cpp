#include "global.hpp"

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;

        // 排序
        sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
             { return u[1] < v[1]; });

        // 状态转移
        int n = intervals.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] <= intervals[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
