#include "../include/global.hpp"

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        array<int, 121> nums = {0};
        int ret = 0;
        for (int age : ages)
        {
            nums[age]++;
        }
        array<int, 121> pre = {0};
        for (int i = 1; i < 121; ++i)
        {
            pre[i] = pre[i - 1] + nums[i];
        }
        for (int i = 15; i < 121; ++i)
        {
            if (nums[i])
            {
                int minAge = i / 2 + 8;
                ret += nums[i] * (pre[i] - pre[minAge - 1] - 1);
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> vec;
    // vec = {16, 16};
    // cout << sol.numFriendRequests(vec) << "\n";
    // vec = {16, 17, 18};
    // cout << sol.numFriendRequests(vec) << "\n";
    // vec = {20, 30, 100, 110, 120};
    // cout << sol.numFriendRequests(vec) << "\n";
    vec = {73, 106, 39, 6, 26, 15, 30, 100, 71, 35, 46, 112, 6, 60, 110};
    cout << sol.numFriendRequests(vec) << "\n";
}