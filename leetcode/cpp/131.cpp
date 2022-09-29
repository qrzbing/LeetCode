#include "global.hpp"

class Solution
{
    vector<vector<string>> ret;
    vector<string> ans;
    vector<vector<bool>> dp;
    int len;

    bool ifPalindrome(string &s, int i, int j)
    {
        for (; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    void dfs(string &s, int i)
    {
        if (i == len)
        {
            ret.emplace_back(ans);
        }

        // 遍历 s，看是否回文
        for (int j = i; j < len; j++)
        {
            if (dp[i][j])
            { // 是子串就切
                ans.push_back(s.substr(i, j - i + 1));
                // 之后继续看下一个子串
                dfs(s, j + 1);
                // 不满足要求就退栈
                ans.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        len = s.length();
        // 进行动态规划，预计算递归字符串
        dp.assign(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                dp[i][j] = ifPalindrome(s, i, j);
            }
        }

        // 回溯满足要求的解
        dfs(s, 0);
        return ret;
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);
    vector<vector<string>> v = {{"a", "a", "b"}, {"aa", "b"}};
    assert(sol.partition("aab") == v);
    Solution sol2;
    v = {{"a"}};
    assert(sol2.partition("a") == v);
    return 0;
}
