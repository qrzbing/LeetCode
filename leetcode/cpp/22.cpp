#include "global.hpp"

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1, vector<string>());
        dp[0] = {""};
        for (int i = 1; i < n + 1; ++i)
        {
            for (int p = 0; p < i; ++p)
            {
                int q = i - p - 1;
                for (string &dp_pstr : dp[p])
                {
                    for (string &dp_qstr : dp[q])
                    {
                        dp[i].emplace_back("(" + dp_pstr + ")" + dp_qstr);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout_vector(sol.generateParenthesis(0));
    cout_vector(sol.generateParenthesis(1));
    cout_vector(sol.generateParenthesis(2));
    cout_vector(sol.generateParenthesis(3));

    return 0;
}
