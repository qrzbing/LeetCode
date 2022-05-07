#include "global.hpp"

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int l = s.length();
        unordered_set<string> us;
        for (auto word : wordDict)
        {
            us.insert(word);
        }

        vector<bool> dp(l + 1, false);

        dp[0] = true; // s[-1:0] = true

        // 从 1 开始遍历 dp，相当于从 0 开始遍历 s。
        for (int i = 1; i <= l; i++)
        {
            // dp[i]=dp[j] && s[j:i] in set
            // 从 0 开始遍历子串 s[0:i]
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && us.find(s.substr(j, i - j)) != us.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
