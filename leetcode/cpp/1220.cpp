#include "global.hpp"

class Solution
{
    int MODN = 1000000007;

public:
    int countVowelPermutation(int n)
    {
        vector<vector<int>> vowel(2, vector<int>(5, 1));
        int S_n1 = 5;
        int curr = 0, last = -1;
        for (int i = 1; i < n; ++i)
        {
            curr = i & 1, last = (i & 1 == 1 ? 0 : 1);
            vowel[curr][0] = vowel[last][1];
            vowel[curr][1] = (vowel[last][0] + vowel[last][2]) % MODN;
            vowel[curr][2] = ((vowel[last][0] + vowel[last][1]) % MODN + (vowel[last][3] + vowel[last][4]) % MODN) % MODN;
            vowel[curr][3] = (vowel[last][2] + vowel[last][4]) % MODN;
            vowel[curr][4] = vowel[last][0];
        }
        return (((vowel[curr][0] + vowel[curr][1]) % MODN + (vowel[curr][2] + vowel[curr][3]) % MODN) % MODN + vowel[curr][4]) % MODN;
    }
};

int main(){
    Solution sol;
    // cout << sol.countVowelPermutation(1) << endl;
    // cout << sol.countVowelPermutation(2) << endl;
    // cout << sol.countVowelPermutation(5) << endl;
    cout << sol.countVowelPermutation(20000) << endl;
}