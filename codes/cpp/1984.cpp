#include "global.hpp"

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int ret = INT32_MAX;
        for (int i = 0; i + k - 1 < l; ++i)
        {
            ret = min(ret, nums[i + k - 1] - nums[i]);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    // v = {9, 4, 1, 7};
    // cout << sol.minimumDifference(v, 3) << endl;
    v = {87063, 61094, 44530, 21297, 95857, 93551, 9918};
    cout << sol.minimumDifference(v, 6) << endl; // 74560
    return 0;
}
