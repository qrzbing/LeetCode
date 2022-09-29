#include "global.hpp"

class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        int upper, lower;
        int l = s.length();
        int maxPos = 0, maxLen = 0;
        for (int i = 0; i < l; ++i)
        {
            upper = 0, lower = 0;
            for (int j = i; j < l; ++j)
            {
                // if (s[j] >= 'a' && s[j] <= 'z')
                if (islower(s[j]))
                {
                    lower |= 1 << (s[j] - 'a');
                }
                // else if(isupper(s[j]))
                else
                {
                    upper |= 1 << (s[j] - 'A');
                }
                if (upper == lower && j - i + 1 > maxLen)
                {
                    maxPos = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(maxPos, maxLen);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestNiceSubstring("YazaAay") << endl;
}