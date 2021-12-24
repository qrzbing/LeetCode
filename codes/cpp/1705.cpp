#include "global.hpp"

typedef pair<int, int> pii;
class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int ret = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n = apples.size();
        int day;
        // 1. 苹果生长的日子
        for (day = 0; day < n; ++day)
        {
            // 扔掉烂苹果
            while (!pq.empty() && pq.top().first <= day)
            {
                pq.pop();
            }
            if (apples[day] > 0)
            {
                pq.emplace(day + days[day], apples[day]);
            }
            if (!pq.empty())
            {
                pii least = pq.top();
                pq.pop();
                if (--least.second > 0)
                {
                    pq.emplace(least.first, least.second);
                }
                ret++;
            }
        }
        // 没有苹果生长的日子
        while (!pq.empty())
        {
            // 先扔掉烂苹果
            while (!pq.empty() && pq.top().first <= day)
            {
                pq.pop();
            }
            if (pq.empty())
                break;
            pii least = pq.top();
            pq.pop();
            // 能吃的苹果数量是 腐烂天数与现在之差和苹果数量的最小值。
            int num = min(least.first - day, least.second);
            ret += num;
            day += num;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> apples, days;
    apples = {1, 2, 3, 5, 2}, days = {3, 2, 1, 4, 2};
    cout << sol.eatenApples(apples, days) << endl;
    apples = {3, 0, 0, 0, 0, 2}, days = {3, 0, 0, 0, 0, 2};
    cout << sol.eatenApples(apples, days) << endl;
}