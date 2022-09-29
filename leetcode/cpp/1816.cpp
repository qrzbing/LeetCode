#include "global.hpp"

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        int l = s.size(), r = 0;
        while (r < l && k)
        {
            if (s.at(r) == ' ')
                k--;
            r++;
        }
        return r < l ? s.substr(0, r - 1) : s;
    }
};

// "chopper is not a tanuki"
// 5