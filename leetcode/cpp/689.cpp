#include "global.hpp"
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> ret;
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxSum123 = 0;
        ;
        for (int i = 2 * k; i < nums.size(); ++i)
        {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i > 3 * k - 2)
            {
                if (sum1 > maxSum1)
                {
                    maxSum1 = sum1;
                    maxSum1Idx = i - 3 * k + 1;
                }
                if (maxSum1 + sum2 > maxSum12)
                {
                    maxSum12 = maxSum1 + sum2;
                    maxSum12Idx1 = maxSum1Idx;
                    maxSum12Idx2 = i - 2 * k + 1;
                }
                if (maxSum12 + sum3 > maxSum123)
                {
                    maxSum123 = maxSum12 + sum3;
                    ret = {maxSum12Idx1, maxSum12Idx2, i - k + 1};
                }
                sum1 -= nums[i - 3 * k + 1];
                sum2 -= nums[i - 2 * k + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ret;
    }
};

vector<int> maxSumOfTwoSubarrays(vector<int> &nums, int k)
{
    vector<int> ret;
    int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
    int sum2 = 0, maxSum12 = 0;
    for (int i = k; i < nums.size(); ++i)
    {
        sum1 += nums[i - k];
        sum2 += nums[i];
        if (i > k * 2 - 2)
        {
            if (sum1 > maxSum1)
            {
                maxSum1 = sum1;
                maxSum1Idx = i - 2 * k + 1;
            }
            if (maxSum1 + sum2 > maxSum12)
            {
                maxSum12 = maxSum1 + sum2;
                ret = {maxSum1Idx, i - k + 1};
            }
            sum1 -= nums[i - k * 2 + 1];
            sum2 -= nums[i - k + 1];
        }
    }
    return ret;
}