#include "global.hpp"

class Solution
{
    int money(vector<int> &nums, int l, int r)
    {
        int pre = nums[l], now = max(pre, nums[l + 1]);
        for (int i = l + 2; i < r; i++)
        {
            int tmp = now;
            now = max(pre + nums[i], now);
            pre = tmp;
        }
        return now;
    }

public:
    int rob(vector<int> &nums)
    {
        int l = nums.size();
        if (l == 1)
        {
            return nums[0];
        }
        if (l == 2)
        {
            return max(nums[0], nums[1]);
        }

        return max(money(nums, 0, l - 1), money(nums, 1, l));
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
