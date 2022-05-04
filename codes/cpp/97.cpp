#include "global.hpp"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length(), k = s3.length();

        if (m + n != k)
            return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        dp[0][0] = true; // dp[0][0] => ["" ""]

        for (int i = 1; i < m; ++i)
        {
            if (dp[i - 1][0] == true && s1[i] == s3[i])
            {
                dp[i][0] = true;
            }
            else
            {
                dp[i][0] = false;
            }
        }
        for (int j = 1; j < n; ++j)
        {
            if (dp[0][j - 1] == true && s2[j] == s3[j])
            {
                dp[0][j] = true;
            }
            else
            {
                dp[0][j] = false;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if ((dp[i - 1][j] == true && s1[i] == s3[i + j]) || (dp[i][j - 1] == true && s2[j] == s3[i + j]))
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
