#include "global.hpp"

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int la = a.length(), lb = b.length();
        int ret = lb / la;
        string str = "";
        for (int i = 0; i < ret; ++i)
        {
            str += a;
        }
        for (int i = ret; i < ret + 3; i++)
        {
            if (str.find(b) != string::npos)
            {
                return i;
            }
            else
            {
                str += a;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.repeatedStringMatch("abcd", "cdabcdab") << "\n";
    cout << sol.repeatedStringMatch("a", "aa") << "\n";
    cout << sol.repeatedStringMatch("a", "a") << "\n";
    cout << sol.repeatedStringMatch("abc", "wxyz") << "\n";
    cout << sol.repeatedStringMatch("cdabab", "cdababcdababcdab") << "\n";
    cout << sol.repeatedStringMatch("cdabab", "abcdababcdab") << "\n";
    cout << sol.repeatedStringMatch("abab", "aba") << "\n";
    cout << sol.repeatedStringMatch("aabaa", "aaab") << "\n";
}