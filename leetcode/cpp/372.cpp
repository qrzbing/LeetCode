#include "global.hpp"

class Solution
{
public:
    int MOD = 1337;
    int littlePow(int a, int b)
    {
        int ret = 1;
        while (b)
        {
            if (b & 0x1)
            {
                ret = (ret * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return ret;
    }
    int superPow(int a, vector<int> &b)
    {
        a = a % MOD;
        if (b.empty())
        {
            return a;
        }
        int ret = 1;
        for (int i = 0; i < b.size(); i++)
        {
            ret = littlePow(ret, 10) * littlePow(a, b.at(i)) % MOD;
        }
        return ret;
    }
};
