#include "global.hpp"
class Solution
{
public:
    int translateNum(int num)
    {
        cout << num << endl;
        if (num >= 100)
        {
            if (num % 100 > 25)
            {
                return translateNum(num / 10);
            }
            if ((num % 100) == (num % 10))
            {
                if (num < 260)
                {
                    return 2;
                }
                return translateNum(num / 10);
            }
            return translateNum(num / 10) + translateNum(num / 100);
        }
        else if (num > 25)
        {
            return 1;
        }
        else
        {
            if (num > 9)
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.translateNum(1068385902) << endl; // 2
    cout << sol.translateNum(10) << endl;         // 2
    cout << sol.translateNum(100) << endl;        // 2
    cout << sol.translateNum(200) << endl;        // 2
    cout << sol.translateNum(648006092) << endl;  // 1
    cout << sol.translateNum(419605557) << endl;  // 2
    cout << sol.translateNum(506) << endl;        // 1
    cout << sol.translateNum(26) << endl;         // 1
}