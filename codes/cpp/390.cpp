#include "global.hpp"

class Solution
{
public:
    int lastRemaining(int n)
    {
        int a1 = 1, step = 1;
        int cnt = n, k = 0;
        while (cnt > 1)
        {
            a1 = ((k++ & 1) ? ((cnt & 1) ? a1 + step : a1) : (a1 + step));
            cnt >>= 1;
            step <<= 1;
        }
        return a1;
    }
};