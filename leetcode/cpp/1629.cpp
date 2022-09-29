#include "global.hpp"

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int n = releaseTimes.size();
        char ret = keysPressed[0];
        int maxTime = releaseTimes[0];
        for (int i = 1; i < n; ++i)
        {
            int tmpTime = releaseTimes[i] - releaseTimes[i - 1];
            if (tmpTime > maxTime)
            {
                ret = keysPressed[i];
                maxTime = tmpTime;
            }
            else if (tmpTime == maxTime)
            {
                ret = max(ret, keysPressed[i]);
            }
        }
        return ret;
    }
};