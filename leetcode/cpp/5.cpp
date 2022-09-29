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
            // [i:i] 是回文的
            dp[i][i] = true;
        }

        int begin_s = 0, len_s = 1;

        // 枚举子串长度
        // 因为 right 越界就会退出，因此字串长度可以设置得宽松一些
        // 在 s.len()==2 的情况下，如果让 i<l 的话会直接退出，这是错误的。
        for (int i = 2; i <= l; ++i)
        {
            int left, right;
            // 枚举左边界
            for (left = 0; left < l; ++left)
            {
                right = left + i - 1;
                // 判断越界
                if (right >= l)
                {
                    break;
                }
                if (s[left] != s[right])
                {
                    dp[left][right] = false;
                }
                else if (right - left < 3)
                {
                    // 判断子串长度为 2 的情况
                    dp[left][right] = true;
                }
                else
                {
                    dp[left][right] = dp[left + 1][right - 1];
                }

                if (dp[left][right] && right - left + 1 > len_s)
                {
                    len_s = right - left + 1;
                    begin_s = left;
                }
            }
        }

        return s.substr(begin_s, len_s);
    }
};

int main()
{
    Solution sol;
    // cout << sol.longestPalindrome("babad") << endl;
    // cout << sol.longestPalindrome("cbbd") << endl;
    // cout << sol.longestPalindrome("ac") << endl;
    cout << sol.longestPalindrome("bb") << endl;
    return 0;
}
