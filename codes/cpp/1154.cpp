#include "global.hpp"

class Solution
{
public:
    int dayOfYear(string date)
    {
        array<int, 12> Month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int ret = 0;
        for (int i = 0; i < month - 1; i++)
        {
            ret += Month[i];
        }
        ret += day;
        if (month > 2 && ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0))
        {
            ret += 1;
        }
        return ret;
    }
};