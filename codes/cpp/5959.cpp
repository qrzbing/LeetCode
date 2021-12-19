#include "global.hpp"

class Solution
{
public:
    int kIncreasing(vector<int> &arr, int k)
    {
        int ret = 0;
        int n = arr.size();
        int l = n / k + 1;
        int m = n % k;
        for (int i = 0; i < k; ++i)
        {
            vector<int> dp(1, arr[i]);
            for (int j = i + k; j < n; j += k)
            {
                auto iter = upper_bound(begin(dp), end(dp), arr[j]);
                if (iter == dp.end())
                {
                    dp.emplace_back(arr[j]);
                }
                else
                {
                    *iter = arr[j];
                }
            }
            ret += l - dp.size();
        }
        return ret - k + m;
    }
};

int main()
{
    Solution sol;
    vector<int> vi = {5, 4, 3, 2, 1};
    cout << sol.kIncreasing(vi, 1) << "\n";
    vi = {4, 1, 5, 2, 6, 2};
    cout << sol.kIncreasing(vi, 2) << "\n";
    vi = {4, 1, 5, 2, 6, 2};
    cout << sol.kIncreasing(vi, 3) << "\n";
    vi = {12, 6, 12, 6, 14, 2, 13, 17, 3, 8, 11, 7, 4, 11, 18, 8, 8, 3};
    cout << sol.kIncreasing(vi, 1) << "\n";
}