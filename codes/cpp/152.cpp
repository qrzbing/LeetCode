#include "global.hpp"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int l = nums.size();
        vector<int> dp_max(l), dp_min(l);

        dp_max[0] = nums[0], dp_min[0] = nums[0];

        for (int i = 1; i < l; i++)
        {
            dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
        }
        return *max_element(dp_max.begin(), dp_max.end());
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
