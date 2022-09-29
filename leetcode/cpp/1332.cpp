#include "global.hpp"

class Solution
{
    bool ifPalindromic(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

public:
    int removePalindromeSub(string s)
    {
        if (ifPalindromic(s, 0, s.length() - 1))
        {
            return 1;
        }
        return 2;
    }
};

int main()
{
    Solution sol;
    cout << sol.removePalindromeSub("ababa") << endl;
    cout << sol.removePalindromeSub("abb") << endl;
    cout << sol.removePalindromeSub("baabb") << endl;
    cout << sol.removePalindromeSub("bbaabaaa") << endl;
}