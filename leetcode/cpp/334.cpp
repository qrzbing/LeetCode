#include "global.hpp"

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int l = nums.size();
        if (l < 3)
            return false;
        vector<int> dp;
        for (int i = 0; i < l; ++i)
        {
            // cout_vector(dp);
            int r = dp.size();
            if (r >= 3)
                return true;
            int l = 0;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (nums[i] <= dp[m])
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }
            if (l < dp.size())
            {
                dp[l] = nums[i];
            }
            else
            {
                dp.emplace_back(nums[i]);
            }
        }
        return dp.size() >= 3 ? true : false;
    }
};

// [2,1,5,0,4,6]

int main()
{
    Solution sol;
    vector<int> vi;
    // vi = {2, 1, 5, 0, 4, 6};
    // cout << sol.increasingTriplet(vi) << endl;
    vi = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << sol.increasingTriplet(vi) << endl;
}