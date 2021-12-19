#include "global.hpp"
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int l = s.length();
        string ret = "";
        int p = 0;
        for (int space : spaces)
        {
            ret += s.substr(p, space - p);
            ret += " ";
            p = space;
        }
        if (p < l)
        {
            ret += s.substr(p, l - p);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> vi = {0,1,2,3,4,5,6};
    cout << sol.addSpaces("spacing", vi) << "\n";
}