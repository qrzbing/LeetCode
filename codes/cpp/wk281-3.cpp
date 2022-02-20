#include "global.hpp"

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> um;
        int vi[27] = {0};
        for (char ch : s)
        {
            vi[ch - 'a'] += 1;
        }
        string ret = "";
        bool canRepeat = false;
        char start = 'z';
        while (start >= 'a')
        {
            char prev = (ret.empty() ? -1 : ret[ret.length() - 1]);
            int tmpl = ret.length();

            for (char ch = start; ch >= 'a'; ch--)
            {
                if (vi[ch - 'a'] == 0 || ch == prev)
                {
                    if (vi[ch - 'a'] == 0 && start == ch)
                    {
                        start--;
                    }
                    continue;
                }
                if (canRepeat == true)
                {
                    canRepeat = false;
                    ret += ch;
                    vi[ch - 'a']--;
                    break;
                }
                for (int j = 0; j < repeatLimit && vi[ch - 'a'] > 0; j++)
                {
                    ret += ch;
                    vi[ch - 'a']--;
                }
                if (vi[ch - 'a'] > 0)
                {
                    canRepeat = true;
                }
                prev = ch;
                break;
            }
            if (ret.length() == tmpl)
            {
                break;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    // cout << sol.repeatLimitedString("cczazcc", 3) << endl;
    // cout << sol.repeatLimitedString("aababab", 2) << endl;
    // cout << sol.repeatLimitedString("robnsdvpuxbapuqgopqvxdrchivlifeepy", 2) << endl;
    // cout << sol.repeatLimitedString("sfcewcajaintjfyvwhfbvxroxgsmgazcsijsxaukxvfiyzfnjsagccecnbmrxtqwnntjbnuswlacckjhpxodflhqksjycvxnorqbyncmprcbfreggaqzuxweetlqapwpclcbgpeftslpqcrvhbtyjethwipvchevdumhcpuntwdayttenocurgouclzgqhlnxxujeixbrpazmzcfjvvnhcueqbaaoeofifpzpkbjrpefdfoukvmdqbizowitwgpeypenmanzktuasbgcpdcnpvsrmkvmgcmabuhlaxmwyjokhglhynqryxqfbmp", 294)
    //      << endl;

    return 0;
}
