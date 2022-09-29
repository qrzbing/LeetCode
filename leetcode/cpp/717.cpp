#include "global.hpp"

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int l = bits.size();
        for (int i = 0; i < l;)
        {
            if (bits[i] == 1)
            {
                if (i == l - 1 || i + 1 == l - 1)
                {
                    return false;
                }
                else
                {
                    i += 2;
                }
            }
            else
            {
                i += 1;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;

    return 0;
}
