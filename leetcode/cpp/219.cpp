#include "global.hpp"

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (um.count(nums[i]) != 0)
            {
                if (i - um[nums[i]] <= k)
                {
                    return true;
                }
            }
            um[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v = {1, 2, 3, 1, 2, 3};
    cout << sol.containsNearbyDuplicate(v, 2) << endl;
}