#include <vector>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        int vfib[2] = {0, 1};
        for (int i = 2; i <= n; ++i)
        {
            int ifib = vfib[0] + vfib[1];
            vfib[i & 0x1] = ifib % 1000000007;
        }
        return vfib[n & 0x1];
    }
};