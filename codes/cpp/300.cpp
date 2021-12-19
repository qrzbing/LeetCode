#include "global.hpp"

class Solution
{

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp;
        dp.emplace_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            int l = 0, r = dp.size();
            while (l < r)
            {
                int m = (l + r) / 2;
                if (nums[i] <= dp[m])
                    r = m;
                else
                    l = m + 1;
            }
            if (l < dp.size())
                dp[l] = nums[i];
            else
                dp.emplace_back(nums[i]);
        }
        return dp.size();
    }
};

int main()
{
    Solution sol;
    vector<int> vi = {10, 9, 2, 5, 3, 7, 101, 18};
    vi = {7, 7, 7, 7, 7, 7, 7};
    cout << sol.lengthOfLIS(vi) << "\n";
}