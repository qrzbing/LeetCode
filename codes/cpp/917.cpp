#include "global.hpp"

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        string chSet = "";
        for (char ch : s)
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            {
                chSet += ch;
            }
        }
        reverse(chSet.begin(), chSet.end());
        for (int i = 0, j = 0; i < s.length(); ++i)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                s[i] = chSet[j];
                j++;
            }
        }
        return s;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
    cout << sol.reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
    return 0;
}
