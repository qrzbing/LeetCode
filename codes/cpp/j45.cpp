#include "global.hpp"

class Solution
{

    long long getSize(long long n)
    {
        if (!n)
            return 1;
        long long ret = 1;
        while (n)
        {
            ret *= 10;
            n /= 10;
        }
        return ret;
    }

public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [this](long long a, long long b) -> bool
             {
                 //  cout << a << " " << b << " " << a * getSize(b) + b << " " << b * getSize(a) + a << "\n";
                 long long sa = a * getSize(b) + b, sb = b * getSize(a) + a;
                 return sa == sb ? a < b : sa < sb;
             });
        string ret = "";

        for (int num : nums)
        {
            ret += to_string(num);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> vi;
    // vi = {3, 30, 34, 5, 9};
    // cout << sol.minNumber(vi) << endl;
    // vi = {4, 404, 401, 40, 441, 439, 423, 456}; // 401 404 423 439 441 456 40 4
    // cout << sol.minNumber(vi) << endl;
    // vi = {401, 40};
    // cout << sol.minNumber(vi) << endl;
    // vi = {12, 121};
    // cout << sol.minNumber(vi) << endl;
    vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << sol.minNumber(vi) << endl;
}