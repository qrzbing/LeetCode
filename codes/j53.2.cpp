#include <vector>
using namespace std;

// class Solution
// {
// public:
//     int missingNumber(vector<int> &nums)
//     {
//         bool arr[10001] = {false};
//         for (auto num : nums)
//         {
//             arr[num] = true;
//         }
//         for (int i = 0; i <= nums.size(); ++i)
//         {
//             if (!arr[i])
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] > m)
            { // in left or this flag
                r = m;
            }
            else
            { // must in right
                l = m + 1;
            }
        }
        return r;
    }
};