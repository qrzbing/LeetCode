#include "global.hpp"

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) < 0 && k > 0)
            {
                nums.at(i) = -nums.at(i);
                k--;
            }
            sum += nums.at(i);
        }
        sort(nums.begin(), nums.end());
        return sum - (k & 1 ? 2 * nums.at(0) : 0);
    }
};