#include "global.hpp"
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (target - nums[i] > nums[j])
                i++;
            else if (target - nums[i] < nums[j])
                j--;
            else
                return {nums[i], nums[j]};
        }
        return {};
    }
};