#include "global.hpp"

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int lhouse = houses.size(), lheater = heaters.size();
        if (lheater == 1)
        {
            return max(abs(heaters[0] - houses[0]), abs(heaters[0] - houses[lhouse - 1]));
        }
        int chouse = 0;
        int maxr = 0;
        for (int i = 0; i < lheater - 1; ++i)
        {
            int m = (heaters[i] + heaters[i + 1]) / 2;
            while (chouse < lhouse && houses[chouse] <= m)
            {
                int r = abs(heaters[i] - houses[chouse]);
                maxr = max(maxr, r);
                chouse++;
            }
        }
        if (chouse != lhouse)
        {
            maxr = max(maxr, abs(heaters[lheater - 1] - houses[lhouse - 1]));
        }
        return maxr;
    }
};

int main()
{
    Solution sol;
    vector<int> houses, heaters;
    // houses = {1, 2, 3}, heaters = {2};
    // cout << sol.findRadius(houses, heaters) << "\n";
    // houses = {1, 2, 3, 4}, heaters = {1, 4};
    // cout << sol.findRadius(houses, heaters) << "\n";
    // houses = {1, 5}, heaters = {2};
    // cout << sol.findRadius(houses, heaters) << "\n";
    // houses = {1}, heaters = {1, 2, 3, 4};
    // cout << sol.findRadius(houses, heaters) << "\n";
    houses = {282475249, 622650073, 984943658, 144108930, 470211272, 101027544, 457850878, 458777923}, heaters = {823564440, 115438165, 784484492, 74243042, 114807987, 137522503, 441282327, 16531729, 823378840, 143542612};
    cout << sol.findRadius(houses, heaters) << "\n"; // 161834419
}