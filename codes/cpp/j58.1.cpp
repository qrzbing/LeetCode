#include "global.hpp"

class Solution
{
public:
    string reverseWords(string s)
    {
        string ret = "";
        int n = s.length();
        int r = n - 1, lb = 0;
        while (r >= 0 && s.at(r) == ' ')
            r--;
        while (lb < n && s.at(lb) == ' ')
            lb++;
        while (r >= lb)
        {
            if (s.at(r) == ' ')
            {
                r--;
                continue;
            }
            int l = r;
            while (l >= lb)
            {
                if (s.at(l) != ' ')
                {
                    l--;
                    continue;
                }
                ret += (s.substr(l + 1, r - l) + " ");
                r = l;
                break;
            }
            if (l == lb - 1 && s.at(l + 1) != ' ')
            {
                ret += s.substr(l + 1, r - l);
                break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.reverseWords("a good   example") << endl;
    cout << sol.reverseWords("the sky is blue") << endl;
    cout << sol.reverseWords("  hello world!  ") << endl;
    cout << sol.reverseWords("") << endl;
    cout << sol.reverseWords("dfvbnm,rfghjnmj") << endl;
    cout << sol.reverseWords("          ") << endl;
}