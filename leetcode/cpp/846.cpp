#include "global.hpp"

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (groupSize == 1)
            return true;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> allCards;
        for (int card : hand)
            allCards[card]++;
        for (auto card : hand)
        {
            if (!allCards[card])
                continue;
            for (int i = 0; i < groupSize; ++i)
            {
                if (allCards[card + i])
                {
                    allCards[card + i] -= 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};