#include "global.hpp"

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int maxLen = 0;
        int ret = 0;
        for (vector<int> &rectangle : rectangles)
        {
            int tmpLen = min(rectangle[0], rectangle[1]);
            if (tmpLen == maxLen)
            {
                ret++;
            }
            else if (tmpLen > maxLen)
            {
                ret = 1;
                maxLen = tmpLen;
            }
        }
        return ret;
    }
};