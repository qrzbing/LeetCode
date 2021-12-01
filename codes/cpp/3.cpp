#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> us;
    int ans = 0, rk = -1;
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        if (i != 0)
        {
            us.erase(s[i - 1]);
        }
        while (rk + 1 < len && !us.count(s[rk + 1]))
        {
            us.insert(s[rk + 1]);
            ++rk;
        }
        ans = max(ans, rk - i + 1);
    }
    return ans;
}