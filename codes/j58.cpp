#include <string>
using namespace std;
class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        string ret_str;
        for (int i = n; i < s.size(); ++i)
        {
            ret_str += s[i];
        }
        for (int i = 0; i < n; ++i)
        {
            ret_str += s[i];
        }
        return ret_str;
    }
};