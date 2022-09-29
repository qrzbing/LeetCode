#include "global.hpp"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int l = nums.size();
        vector<int> dp(l);
        dp[0] = nums[0];
        if (l > 1)
        {
            dp[1] = max(nums[0], nums[1]);
        }
        else
        {
            return dp[0];
        }

        for (int i = 2; i < l; ++i)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[l - 1];
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    vector<int> v;
    v = {1, 2, 3, 1};
    assert(sol.rob(v) == 4);
    v = {2, 7, 9, 3, 1};
    assert(sol.rob(v) == 12);
    v = {0};
    assert(sol.rob(v) == 0);
    return 0;
}
