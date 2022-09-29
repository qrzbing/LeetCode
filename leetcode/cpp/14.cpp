#include "global.hpp"

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        for (int i = 0; i < strs[0].size(); ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution sol;
    vector<string> v1{"123", "1"};
    vector<string> v2{"flower", "flower", "flower"};
    cout << sol.longestCommonPrefix(v1) << endl;
    cout << sol.longestCommonPrefix(v2) << endl;
}