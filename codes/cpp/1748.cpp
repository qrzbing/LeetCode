#include "global.hpp"

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int size = nums.size() + 1;
        int ret = 0;
        vector<int> inum(101, 0);
        for (int num : nums)
        {
            inum[num] += 1;
        }
        for (int i = 1; i < 101; i++)
        {
            if (inum[i] == 1)
            {
                ret += i;
            }
        }
        return ret;
    }
};