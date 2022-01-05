#include "global.hpp"

class Solution
{
public:
    string modifyString(string s)
    {
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    if (i == 0)
                    {
                        if (ch != s[i + 1])
                        {
                            s[i] = ch;
                            break;
                        }
                    }
                    else if (i == len - 1)
                    {
                        if (ch != s[i - 1])
                        {
                            s[i] = ch;
                            break;
                        }
                    }
                    else
                    {
                        if (ch != s[i - 1] && ch != s[i + 1])
                        {
                            s[i] = ch;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};