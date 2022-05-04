#include "global.hpp"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int right = 0;
        int maxJump = 0;
        for (int i = 0; i < len - 1; i++)
        {
            maxJump = max(maxJump, nums[i] + i);
            if (maxJump <= i)
                return false;
            if (i == right)
            {
                right = nums[i] + i;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v = {2, 3, 1, 1, 4};
    assert(sol.canJump(v) == true);
    v = {3, 2, 1, 0, 4};
    assert(sol.canJump(v) == false);
    return 0;
}
