#include "global.hpp"

class DetectSquares
{
    unordered_map<int, unordered_map<int, int>> Points; // x, y, numsof(x, y)

public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        Points[point[0]][point[1]] += 1;
    }

    int count(vector<int> point)
    {
        int x = point[0], y = point[1];
        if (Points.count(x) == 0) // Points at not exist
        {
            return 0;
        }
        unordered_map<int, int> &xCount = Points[x];
        int ret = 0;
        for (auto &[col, colCnt] : Points)
        {
            if (col != x) // 当前的点集就是 x，不和自己计算比较。
            {
                int d = col - x; // 首先求出边长
                // 上下边是对称的。
                // 三个点分别是：
                // colCnt[y] 同一行的点
                // xCount[y + d] 同一列的点
                // colCnt[y + d] 对角上的点
                if (colCnt.count(y) != 0)
                { // 没有同一列的点则继续枚举下一个 y 上的点集
                    ret += colCnt[y] * (xCount.count(y + d) ? xCount[y + d] : 0) * (colCnt.count(y + d) ? colCnt[y + d] : 0);
                    ret += colCnt[y] * (xCount.count(y - d) ? xCount[y - d] : 0) * (colCnt.count(y - d) ? colCnt[y - d] : 0);
                }
            }
        }
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main()
{
    DetectSquares *obj = new DetectSquares();
    obj->add({3, 10});
    obj->add({11, 2});
    obj->add({3, 2});
}