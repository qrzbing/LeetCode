#include "global.hpp"

class Solution
{
    int len;

public:
    bool checkRange(string &s, string &locked, int l)
    {
        int check = 0;
        for (int i = l; i < len; ++i)
        {
            if (s[i] == '(')
            {
                check++;
            }
            else
            {
                if (!check)
                {
                    if (locked.at(i) == '1')
                    {
                        return false;
                    }
                    else
                    {
                        return checkRange(s, locked, l + 1);
                    }
                }
                check--;
            }
        }
    }
    bool canBeValid(string s, string locked)
    {
        len = s.length();

        return checkRange(s, locked, 0);
    }
};

int main()
{
    Solution sol;
    // cout << sol.canBeValid("))()))", "010100") << "\n";
    // cout << sol.canBeValid(")(", "00") << "\n";
    cout << sol.canBeValid("((()(()()))()((()()))))()((()(()",
                           "10111100100101001110100010001001")
         << "\n";
}