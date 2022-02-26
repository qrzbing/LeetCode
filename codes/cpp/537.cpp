#include "global.hpp"

class Solution
{
    pair<int, int> stringToComplex(string &s)
    {
        pair<int, int> ret;
        int l = s.length();
        int i = 1;
        for (; i < l; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                break;
            }
        }
        string fir = s.substr(0, i);
        // cout << fir << endl;
        ret.first = stoi(fir);
        if (s[l - 1] == 'i')
        {
            string sec = s.substr(i + 1, l - i - 1);
            // cout << sec << endl;
            ret.second = stoi(sec);
        }
        else
        {
            ret.second = 0;
        }
        return ret;
    }

public:
    string complexNumberMultiply(string num1, string num2)
    {
        pair<int, int> c1 = stringToComplex(num1), c2 = stringToComplex(num2);
        // cout << c1.first << " " << c1.second << endl;
        // cout << c2.first << " " << c2.second << endl;
        int fir = c1.first * c2.first - c1.second * c2.second;
        int sec = c1.first * c2.second + c1.second * c2.first;
        string ret = to_string(fir) + "+" + to_string(sec) + "i";
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.complexNumberMultiply("1+1i", "1+1i") << endl;
    cout << sol.complexNumberMultiply("1+-1i", "1+-1i") << endl;
    cout << sol.complexNumberMultiply("-10+-10i", "12+-14i") << endl;
    cout << sol.complexNumberMultiply("0+-10i", "12+-14i") << endl;
    return 0;
}
