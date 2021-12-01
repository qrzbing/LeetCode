#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string ret_str;
        for (auto ch : s)
        {
            if (ch == ' ')
            {
                ret_str.append(string("%20"));
            }
            else
            {
                ret_str += ch;
            }
        }
        return ret_str;
    }
};