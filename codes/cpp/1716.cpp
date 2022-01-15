#include "global.hpp"

class Solution
{
public:
    int totalMoney(int n)
    {
        int week_i = 1;
        int ret = 0;
        for (; n >= 7; n -= 7, week_i++)
            ret = ret + week_i * 7 + 21; // + (week_i + week_i + 6) * 7 / 2;
        return ret + (week_i + week_i + n - 1) * n / 2;
    }
};

int main()
{
    Solution sol;
    cout << sol.totalMoney(10) << endl; // 37
}