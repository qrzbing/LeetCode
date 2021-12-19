#include "global.hpp"

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long count = 1;
        int n = prices.size();
        if (n == 1)
            return 1;
        long long ret = 0;
        for (int i = 1; i < n; ++i)
        {
            if (prices[i - 1] - prices[i] == 1)
            {
                count++;
            }
            else
            {
                ret += (1 + count) * count / 2;
                count = 1;
            }
        }
        ret += (1 + count) * count / 2;
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> vi = {3,2,1,4};
    cout << sol.getDescentPeriods(vi) << "\n";
}