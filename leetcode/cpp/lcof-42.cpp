#include "global.hpp"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ret = -101;
        int pre = -101;
        for (auto num : nums)
        {
            pre = max(num, pre + num);
            ret = max(pre, ret);
        }
        return ret;
    }
};