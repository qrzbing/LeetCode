#include "global.hpp"

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int len = s.length();
        // vector<int> dp(len);
        // dp[0] = 1;
        // dp[-1] = 1;
        //
        int pre = 1, curr = 1; // dp[-1] = 1;

        for (int i = 1; i < len; ++i)
        {
            int tmp = curr;
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                {
                    curr = pre;
                }
                else
                {
                    return 0;
                }
            }
            else if (s[i - 1] == '1')
            {
                curr = curr + pre;
            }
            else if (s[i - 1] == '2')
            {
                if (s[i] >= '0' && s[i] <= '6')
                {
                    curr = curr + pre;
                }
            }
            pre = tmp;
        }

        return curr;
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    assert(sol.numDecodings("12") == 2);
    assert(sol.numDecodings("226") == 3);
    assert(sol.numDecodings("0") == 0);
    assert(sol.numDecodings("27") == 1);
    assert(sol.numDecodings("10011") == 0);
    assert(sol.numDecodings("301") == 0);
    return 0;
}
