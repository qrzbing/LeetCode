#include "global.hpp"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length(), n = s2.length(), k = s3.length();
        // cout << m << " " << n << endl;
        if (m + n != k)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true; // dp[0][0] => ["" ""]

        // 列的访问，实质上是比较 s2
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = dp[i - 1][0] && s2[i - 1] == s3[i - 1];
        }
        // 行的访问，实质上是比较 s1
        for (int j = 1; j <= m; ++j)
        {
            dp[0][j] = dp[0][j - 1] && s1[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i - 1][j] && s2[i - 1] == s3[i + j - 1]) ||  // s2
                           (dp[i][j - 1] && s1[j - 1] == s3[i + j - 1]) ;   // s1
            }
        }

        // cout_2d_vector(dp);

        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    assert(sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);
    assert(sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);
    assert(sol.isInterleave("", "", "") == true);
    assert(sol.isInterleave("a", "", "a") == true);
    assert(sol.isInterleave("db", "b", "cbb") == false);
    return 0;
}
