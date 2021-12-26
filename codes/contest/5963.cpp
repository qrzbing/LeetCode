#include "global.hpp"

class Solution
{
public:
    int reverseInt(int num)
    {
        if (!num)
            return 0;
        int ret = 0;
        while (num > 0)
        {
            ret = ret * 10 + (num % 10);
            num /= 10;
            // cout << ret << endl;
        }
        return ret;
    }
    bool isSameAfterReversals(int num)
    {
        if (reverseInt(reverseInt(num)) == num)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isSameAfterReversals(1800) << endl;
    cout << sol.isSameAfterReversals(180081) << endl;
}