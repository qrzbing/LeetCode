#include "../include/global.hpp"

class Solution
{
    int len;
    int executeOneTime(int n, vector<int> &startPos, string &s, int loc)
    {
        int row = startPos[0], col = startPos[1];
        for (int i = loc; i < len; ++i)
        {
            switch (s[i])
            {
            case 'R':
                col++;
                break;
            case 'D':
                row++;
                break;
            case 'U':
                row--;
                break;
            case 'L':
                col--;
                break;
            default:
                break;
            }
            if (row < 0 || col < 0 || row >= n || col >= n)
            {
                return i - loc;
            }
        }
        return len - loc;
    }

public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        len = s.length();
        vector<int> ret(len);
        for (int i = 0; i < len; ++i)
        {
            ret[i] = executeOneTime(n, startPos, s, i);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> startPos = {0, 1};
    cout_vector(sol.executeInstructions(3, startPos, "RRDDLU"));
}