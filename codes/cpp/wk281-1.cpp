#include "global.hpp"

class Solution
{
public:
    int countEven(int num)
    {
        int ret = 0, i = 0;
        for (; num - i >= 10; i += 10)
        {
            ret += 5;
        }
        for (i; i <= num; i++)
        {
            int t = i;
            int sum = 0;
            while (t > 0)
            {
                sum += t % 10;
                t /= 10;
            }
            if ((sum & 1) == 0)
            {
                ret++;
            }
        }
        return ret - 1;
    }
};

int main()
{
    Solution sol;
    cout << sol.countEven(30) << endl;
    cout << sol.countEven(4) << endl;
    cout << sol.countEven(1000) << endl;
    return 0;
}
