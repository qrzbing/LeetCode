#include "global.hpp"

class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        int l = nums.size();
        string ret = to_string(nums[0]);
        if (l == 1)
            return ret;
        if (l > 2)
        {
            ret += "/(";
            for (int i = 1; i < l; ++i)
            {
                ret += to_string(nums[i]);
                if (i < l - 1)
                {
                    ret += "/";
                }
            }
            ret += ")";
        }
        else
        {
            ret += "/" + to_string(nums[1]);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    v = {2};
    cout << sol.optimalDivision(v) << endl;
    v = {2, 3};
    cout << sol.optimalDivision(v) << endl;
    v = {3, 4, 5};
    cout << sol.optimalDivision(v) << endl;
    return 0;
}
