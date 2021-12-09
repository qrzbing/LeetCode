#include "global.hpp"

class Solution
{
public:
    int mm, nn, kk;
    int countSum(int num)
    {
        int ret = 0;
        while (num)
        {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
    int dfs(vector<vector<bool>> &map, int i, int j)
    {
        if (i < 0 || j < 0 || i >= mm || j >= nn || map[i][j] || countSum(i) + countSum(j) > kk)
        {
            return 0;
        }
        map[i][j] = true;
        return 1 + dfs(map, i - 1, j) + dfs(map, i + 1, j) + dfs(map, i, j - 1) + dfs(map, i, j + 1);
    }
    int movingCount(int m, int n, int k)
    {
        mm = m, nn = n, kk = k;
        vector<vector<bool>> map(m, vector<bool>(n, false));
        return dfs(map, 0, 0);
    }
};

int main()
{
    Solution sol;
    cout << sol.movingCount(2, 3, 1) << endl; // 3
    cout << sol.movingCount(3, 1, 0) << endl; // 1
    cout << sol.movingCount(1, 2, 1) << endl; // 2
}