#include "global.hpp"

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int l = dominoes.length();
        vector<int> vi;
        for (int i = 0; i < l; ++i)
        {
            if (dominoes[i] != '.')
            {
                vi.emplace_back(i);
            }
        }
        int lidx = vi.size();
        for (int i = 0; i < lidx; ++i)
        {
            if (dominoes[vi[i]] == 'L')
            {
                int j = 0;
                if (i <= 0)
                {
                    j = 0;
                }
                else
                {
                    if (dominoes[vi[i - 1]] == 'R')
                    {
                        int mid = (vi[i] + vi[i - 1]) / 2;
                        j = mid + 1;
                    }
                    else
                    {
                        j = vi[i - 1];
                    }
                }
                for (j; j < vi[i]; ++j)
                {
                    dominoes[j] = 'L';
                }
            }
            else
            {
                int right = 0;
                if (i >= lidx - 1)
                {
                    right = l;
                }
                else
                {
                    // cout << i + 1 << " " << lidx << endl;
                    if (dominoes[vi[i + 1]] == 'L')
                    {
                        int ad = vi[i] + vi[i + 1];
                        int mid = (ad & 1 == 0) ? (ad / 2) : ((ad + 1) / 2);
                        right = mid;
                    }
                    else
                    {
                        right = vi[i + 1];
                    }
                }
                for (int j = vi[i]; j < right; ++j)
                {
                    dominoes[j] = 'R';
                }
            }
        }
        return dominoes;
    }
};

int main()
{
    Solution sol;
    cout << sol.pushDominoes(".L.R...LR..L..") << endl;
    cout << sol.pushDominoes("RR.L") << endl;
    cout << sol.pushDominoes(".L.R.") << endl;
    return 0;
}
