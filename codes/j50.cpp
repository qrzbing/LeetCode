#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, bool> um;
        vector<char> vc;
        for (auto ch : s)
        {
            if (um.find(ch) != um.end())
            {
                um[ch] = false;
            }
            else
            {
                vc.push_back(ch);
                um[ch] = true;
            }
        }
        for (auto ch : vc)
        {
            if (um[ch])
            {
                return ch;
            }
        }
        return ' ';
    }
};

int main()
{
    string s = "leetcode";
    Solution sol;
    char ch = sol.firstUniqChar(s);
}