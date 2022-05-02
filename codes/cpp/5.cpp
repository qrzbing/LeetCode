#include "global.hpp"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = s.length();
        if (l < 2)
        {
            return s;
        }
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        int maxLen = 1;
        for (int i = 0; i < l; ++i)
        {
            // [i:i] is Palindrome
            dp[i][i] = true;
        }
    }
};

int main()
{
    Solution sol;

    return 0;
}
