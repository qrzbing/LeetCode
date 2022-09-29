#include "global.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> um;
        int ret = 0;
        int len = 0;
        int l = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!um.count(s[i]))
            {
                um[s[i]] = i;
                len++;
            }
            else
            {
                if (l < um[s[i]])
                {
                    len = i - um[s[i]];
                }
                else
                {
                    len = i - l;
                }
                l = max(l, um[s[i]]);
                um[s[i]] = i;
            }
            ret = max(ret, len);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLongestSubstring("tmmzuxt") << endl;
}