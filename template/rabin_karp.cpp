#include <string>
using namespace std;

int pow(int a, int n, int mod)
{
    return 0;
}

int rabinKarp(string s, int mod, int base)
{
    int n = s.length();
    int ret = 0;
    int mulbase = 1;
    for (int i = 0; i <= n; i++, mulbase = base * mulbase % mod)
    {
        // ret += (s[i] - 'a') * pow(base, i - n + 1, mod);
        ret += (s[i] - 'a') * mulbase % mod;
    }
    return ret;
}