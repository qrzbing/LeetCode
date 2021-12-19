#include "global.hpp"

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (string &word : words)
        {
            bool flag = true;
            for (int i = 0, j = word.length() - 1; i < j; i++, j--)
            {
                if (word[i] != word[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return word;
            }
        }
        return "";
    }
};

int main()
{
    Solution sol;
    vector<string> vs = {"cqllrtyhw", "swwisru", "gpzmbders", "wqibjuqvs", "pp", "usewxryy", "ybqfuh", "hqwwqftgyu", "jggmatpk"};
    cout << sol.firstPalindrome(vs) << endl;
}