#include "global.hpp"

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        double tx = myPow(x, n / 2);
        if (n & 1)
        {
            if (n > 0)
            {
                return tx * tx * x;
            }
            else
            {
                return tx * tx / x;
            }
        }
        else
            return tx * tx;
    }
};

// 2.00000 -2
// 34.00515 -3

int main()
{
    Solution sol;
    cout << sol.myPow(34.00515, -3) << endl;
}