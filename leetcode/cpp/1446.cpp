#include "global.hpp"

class Solution
{
public:
    int maxPower(string s)
    {
        int count = 1;
        int ret = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            count = (s[i] == s[i - 1]) ? count + 1 : 1;
            ret = max(count, ret);
        }
        return ret;
    }
};