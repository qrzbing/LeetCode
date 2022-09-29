#include "global.hpp"

class Solution
{
    int l;
    string addStringNums(string &a, string &b)
    {
        int carry = 0;
        string ret = "";
        int i, j;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int c;
            c = ((i < 0) ? (b[j] - '0') : (j < 0 ? (a[i] - '0') : (a[i] - '0') + (b[j] - '0')));
            c += carry;
            if (c >= 10)
            {
                carry = 1;
                c -= 10;
            }
            else
                carry = 0;
            ret = string(1, (char)(c + '0')) + ret;
        }
        return carry > 0 ? "1" + ret : ret;
    }
    bool checkFirstSecond(string &num, int left_r, int right_r)
    {

        bool ret = false;
        int left_l = 0;
        for (int num_r = right_r + 1; num_r < l; num_r++)
        {
            if (num[right_r + 1] == '0' && num_r > right_r + 1)
                return false;
            string left = num.substr(left_l, left_r - left_l + 1),
                   right = num.substr(left_r + 1, right_r - left_r),
                   sum = num.substr(right_r + 1, num_r - right_r);
            // cout << left << " " << right << " " << sum << " " << addStringNums(left, right) << endl;
            if (addStringNums(left, right) == sum)
            {
                left_l = left_r + 1;
                left_r = right_r;
                right_r = num_r;
                // num_r += 1;
                ret = true;
            }
            else
            {
                ret = false;
            }
        }
        return ret;
    }

public:
    bool isAdditiveNumber(string num)
    {
        l = num.length();
        if (l < 3)
            return false;

        int left_l = 0, left_r = 0, right_l = 1, right_r = 1, num_l = 2, num_r = 2;
        for (left_r = 0; left_r < l; ++left_r)
        {
            // if (num[left_r + 1] == '0')
            //     continue;
            for (right_r = left_r + 1; right_r < l; ++right_r)
            {
                if (num[left_r + 1] == '0' && right_r > left_r + 1)
                {
                    break;
                }
                if (checkFirstSecond(num, left_r, right_r))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isAdditiveNumber("112358") << endl;
    cout << sol.isAdditiveNumber("199100199") << endl;
    cout << sol.isAdditiveNumber("101") << endl;
    cout << sol.isAdditiveNumber("000") << endl;
    cout << sol.isAdditiveNumber("198019823962") << endl;
}