#include "global.hpp"

class Solution
{
public:
    int numberOfMatches(int n)
    {
        int ret = 0;
        while (n > 1)
        {
            int toAdd = n >> 1;
            ret += toAdd;
            n = ((n & 1) ? toAdd + 1 : toAdd);
        }
        return ret;
    }
};