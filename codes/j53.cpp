#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int l = 0, r = nums.size() - 1;
        int left = -1, right = -1;

        // left boundry
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] >= target)
            { // search left
                r = m - 1;
            }
            else
            { //search right
                l = m + 1;
            }
        }
        left = r;
        if (left + 1 < nums.size() && nums[left + 1] != target)
        {
            return 0;
        }

        // right boundry
        l = left + 1, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > target)
            { // search left
                r = m - 1;
            }
            else
            { //search right
                l = m + 1;
            }
        }
        right = l;
        return right - left - 1;
    }
};

int main()
{
    // vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> nums = {2, 2};
    Solution sol;
    cout << sol.search(nums, 3) << "\n";
}