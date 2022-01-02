#include "global.hpp"

class Solution
{
public:
    int lastRemaining(int n)
    {
        int a1 = 1, an = n, step = 1;
        int cnt = n, k = 0;
        while (cnt > 1)
        {
            if (k & 1)
            { // 反向
                an = an - step;
                a1 = ((cnt & 1) ? a1 + step : a1);
            }
            else
            { // 正向
                a1 = a1 + step;
                an = ((cnt & 1) ? an - step : an);
            }
            k++;
            cnt >>= 1;
            step <<= 1;
        }
        return a1;
    }
};