#include "global.hpp"

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int ret = 0;
        int n = nums.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; ++i)
        {
            ret += (um.count(nums[i] + k) ? um[nums[i] + k] : 0);
            ret += (um.count(nums[i] - k) ? um[nums[i] - k] : 0);
            um[nums[i]] += 1;
        }
        return ret;
    }
};

int main()
{

    return 0;
}
