#include "global.hpp"

class Solution
{
    int m, n;
    double getKthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int r1 = 0, r2 = 0;
        while (true)
        {
            // 边界情况：某个数组为空
            if (r1 == m)
            {
                return nums2[r2 + k - 1];
            }
            if (r2 == n)
            {
                return nums1[r1 + k - 1];
            }
            // 边界情况：k==1
            if (k == 1)
            {
                return min(nums1[r1], nums2[r2]);
            }
            // 正常情况
            int half = k / 2;
            int newr1 = min(m - 1, r1 + half - 1), newr2 = min(n - 1, r2 + half - 1);
            if (nums1[newr1] <= nums2[newr2])
            {
                k -= (newr1 - r1 + 1);
                r1 = newr1 + 1;
            }
            else
            {
                k -= (newr2 - r2 + 1);
                r2 = newr2 + 1;
            }
        }
        return 0.0;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        m = nums1.size(), n = nums2.size();
        int l = m + n;
        if ((l % 2) & 1)
        {
            return getKthElement(nums1, nums2, l / 2 + 1);
        }
        else
        {
            return (getKthElement(nums1, nums2, l / 2) + getKthElement(nums1, nums2, l / 2 + 1)) / 2;
        }
    }
};

// [1,3]
// [2]