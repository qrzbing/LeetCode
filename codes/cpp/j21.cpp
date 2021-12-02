#include "global.hpp"

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < nums.size())
        {
            if (!(nums[ptr1] & 0x1))
            {
                if (ptr2 >= nums.size())
                {
                    break;
                }
                while (ptr2 < nums.size())
                {
                    if ((nums[ptr2] & 0x1) && (ptr2 > ptr1))
                    {
                        swap(nums[ptr1], nums[ptr2]);
                        break;
                    }
                    ptr2++;
                }
            }
            ptr1++;
        }
        return nums;
    }
};

int main()
{
    vector<int> vi = {1, 2, 3, 4};
    Solution sol;
    sol.exchange(vi);
}