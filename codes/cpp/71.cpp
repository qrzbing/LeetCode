#include "global.hpp"

class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.length();
        int i, j;
        string ret = "";
        for (i = 1; i < len; i = j + 1)
        {
            j = i;
            while (j < len)
            {
                if (path[j] == '/')
                    break;
                j++;
            }
            string tmpPath = path.substr(i, j - i);
            if (tmpPath.empty() || tmpPath == ".")
                continue;
            if (tmpPath == "..")
            {
                int ret_len = ret.length();
                if (ret_len <= 1)
                    continue;
                int k = ret_len - 1;
                while (k >= 0)
                {
                    if (ret[k] == '/')
                        break;
                    k--;
                }
                ret = ret.substr(0, k);
                continue;
            }
            ret = ret + "/" + tmpPath;
        }
        return ret.empty() ? "/" : ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.simplifyPath("/home/") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/a/./b/../../c/") << endl;
}