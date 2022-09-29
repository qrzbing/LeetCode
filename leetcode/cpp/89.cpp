#include "global.hpp"

class Solution
{
    long pow(long a, long n)
    {
        if (!n)
            return 1;
        long pow_num = pow(a, n / 2);
        if (n & 1)
            return (pow_num * pow_num) * a;
        else
            return (pow_num * pow_num);
    }

public:
    vector<int> grayCode(int n)
    {
        long length = pow(2, n);
        vector<int> ret(length);
        for (long i = 0; i < length; ++i)
        {
            ret[i] = i ^ (i >> 1);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout_vector(sol.grayCode(16));
}