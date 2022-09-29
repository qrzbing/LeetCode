#include "global.hpp"

class Solution
{
    vector<int> fibVec;

public:
    int findMinFibonacciNumbers(int k)
    {
        fibVec = {1, 1};
        int a = 1, b = 1;
        while (a + b <= k)
        {
            int c = a + b;
            cout << c << endl;
            fibVec.emplace_back(c);
            a = b;
            b = c;
        }
        int ret = 0;
        for (int i = fibVec.size() - 1; k > 0 && i >= 0; i--)
        {
            if (fibVec[i] > k)
                continue;
            k -= fibVec[i];
            ret++;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    // cout << sol.findMinFibonacciNumbers(7) << endl;
    cout << sol.findMinFibonacciNumbers(5) << endl;
}