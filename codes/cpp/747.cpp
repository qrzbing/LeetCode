#include "global.hpp"

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int l = nums.size();
        int curr_max = 0;
        int ret = 0;
        for (int i = 1; i < l; ++i)
        {
            int num = nums[i], num_max = nums[curr_max];
            if (num > num_max)
            {
                ret = ((num_max * 2 <= num) ? i : -1);
                curr_max = i;
            }
            else
            {
                ret = (num * 2 > num_max) ? -1 : ret;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> vi;
    vi = {3, 6, 1, 0};
    cout << sol.dominantIndex(vi) << endl;
    vi = {1, 2, 3, 4};
    cout << sol.dominantIndex(vi) << endl;
}