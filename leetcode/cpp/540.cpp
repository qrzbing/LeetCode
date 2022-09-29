#include "global.hpp"

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if ((m % 2 == 1 && nums[m] == nums[m - 1]) || (m % 2 == 0 && nums[m] == nums[m + 1]))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return nums[l];
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(v) << endl;
    v = {3, 3, 7, 7, 10, 11, 11};
    cout << sol.singleNonDuplicate(v) << endl;
    return 0;
}
