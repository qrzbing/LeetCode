#include "global.hpp"

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int sum_num = 0;
        for (int i = 2; i < sqrt(num); ++i)
        {
            if (!(num % i))
            {
                sum_num += i;
                sum_num += num / i;
            }
        }
        sum_num += 1;
        if (sum_num == num)
            return true;
        return false;
    }
};

int main()
{
    Solution sol;
    // cout << sol.checkPerfectNumber(28) << "\n";
    cout << sol.checkPerfectNumber(1) << "\n";
}