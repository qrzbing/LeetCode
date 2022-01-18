#include "global.hpp"

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int tb_size = timePoints.size();
        if(tb_size > 1440)
            return 0;
        vector<int> timeTable;
        for (string &timePoint : timePoints)
            timeTable.emplace_back(stoi(timePoint.substr(0, 2)) * 60 + stoi(timePoint.substr(3, 2)));
        sort(timeTable.begin(), timeTable.end());
        
        int ret = 1440;
        for (int i = 0; i < tb_size - 1; ++i)
            ret = min(timeTable[i + 1] - timeTable[i], ret);
        return min(ret, timeTable[0] + 1440 - timeTable[tb_size - 1]);
    }
};