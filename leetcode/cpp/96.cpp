#include "global.hpp"

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                // cout << i << " " << j << endl;
                dp[i] += dp[j - 1] * dp[i - j];
            }
            // cout << i << " " << dp[i] << endl;
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    assert(sol.numTrees(3) == 5);
    assert(sol.numTrees(4) == 14);
    return 0;
}
