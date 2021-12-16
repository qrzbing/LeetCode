#include "global.hpp"

class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        int sameCnt = 0;
        vector<double> degrees;
        for (vector<int> &point : points)
        {
            if (point[0] == location[0] && point[1] == location[1])
            {
                sameCnt++;
                continue;
            }
            degrees.emplace_back(atan2(point[1] - location[1], point[0] - location[0]));
        }
        sort(degrees.begin(), degrees.end());
        int n = degrees.size();
        for (int i = 0; i < n; ++i)
        {
            degrees.emplace_back(degrees[i] + 2 * M_PI);
        }
        int maxCnt = 0;
        // 将 angle 转换为 degree。
        double angle2degree = angle * M_PI / 180;
        // n = degrees.size();
        // 由于加2π的操作只是为了避免滑动窗口反转，因此滑动范围只需要覆盖之前的窗口即可。
        int j = 0;
        // 这里 j 指向的是大于 i 所在位置的第一个点
        for (int i = 0; i < n; ++i)
        {
            while (j < degrees.size() && degrees[j] <= degrees[i] + angle2degree)
            {
                j++;
            }
            maxCnt = max(j - i, maxCnt);
        }
        return maxCnt + sameCnt;
    }
};

int main()
{
    Solution sol;
}

// [[41,7],[22,94],[90,53],[94,54],[58,50],[51,96],[87,88],[55,98],[65,62],[36,47],[91,61],[15,41],[31,94],[82,80],[42,73],[79,6],[45,4]]
// 17
// [6,84]
// : 7