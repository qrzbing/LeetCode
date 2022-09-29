#include "global.hpp"
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int price_min = 0x7fffffff, price_max = 0;
        for (auto price : prices)
        {
            price_min = min(price_min, price);
            price_max = max(price_max, price - price_min);
        }
        return price_max;
    }
};