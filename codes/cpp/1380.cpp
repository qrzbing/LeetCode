#include "global.hpp"

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ret;
        for (vector<int> &line : matrix)
        {
            int min_num = *min_element(line.begin(), line.end());
            for (int i = 0; i < n; ++i)
            {
                if (line[i] == min_num)
                {
                    bool flag = true;
                    for (int j = 0; j < m; ++j)
                    {
                        if (matrix[j][i] > min_num)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        ret.emplace_back(min_num);
                    }
                    break;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;

    return 0;
}
