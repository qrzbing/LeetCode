#include "global.hpp"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[size - 1][0];
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    vector<int> v;
    v = {7, 1, 5, 3, 6, 4};
    assert(sol.maxProfit(v) == 7);
    v = {1, 2, 3, 4, 5};
    assert(sol.maxProfit(v) == 4);
    v = {7, 6, 4, 3, 1};
    assert(sol.maxProfit(v) == 0);
    return 0;
}
