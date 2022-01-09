#include "global.hpp"

class Solution
{
public:
    int maxDepth(string s)
    {
        int ret = 0;
        int curr = 0;
        for (char ch : s)
            switch (ch)
            {
            case '(':
                ret = max(ret, ++curr);
                break;
            case ')':
                --curr;
            default:
                break;
            }
        return ret;
    }
};