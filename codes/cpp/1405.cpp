#include "global.hpp"

class Solution
{
    using pci = pair<char, int>;

public:
    string longestDiverseString(int a, int b, int c)
    {
        array<pci, 3> v = {pci{'a', a}, pci{'b', b}, pci{'c', c}};
        int maxC = max({a, b, c});
        int maxFlag = (maxC == a ? 0 : (maxC == b ? 1 : 2));
        int flag1 = (maxFlag + 1) % 3, flag2 = (maxFlag + 2) % 3;
        string ret = "";
        int oldMax = -1;
        while (v[maxFlag].second > 0)
        {
            // cout << maxFlag << " " << flag1 << " " << flag2 << endl;
            ret += v[maxFlag].first;
            if (--v[maxFlag].second > 0)
            {
                if (oldMax == -1 || v[maxFlag].second > v[oldMax].second)
                {
                    ret += v[maxFlag].first;
                    v[maxFlag].second--;
                }
            }
            oldMax = maxFlag;
            maxFlag = (v[flag1].second > v[flag2].second ? flag1 : flag2);
            flag1 = (maxFlag + 1) % 3;
            flag2 = (maxFlag + 2) % 3;
            // cout << v[maxFlag].second << " " << v[flag1].second << " " << v[flag2].second << endl;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestDiverseString(1, 1, 7) << endl; // "ccaccbcc"
    cout << sol.longestDiverseString(2, 2, 1) << endl; // "aabbc"
    cout << sol.longestDiverseString(7, 1, 0) << endl; // "aabaa"
    cout << sol.longestDiverseString(0, 8, 11) << endl; // "ccbccbbccbbccbbccbc"
}