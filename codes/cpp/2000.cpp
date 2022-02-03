#include "global.hpp"

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int l = word.size();
        int r = 0;
        for (; r < l; ++r)
        {
            if (word[r] == ch)
            {
                reverse(word.begin(), word.begin() + r + 1);
                break;
            }
        }
        return word;
    }
};

int main()
{
    Solution sol;
    cout << sol.reversePrefix("abcdefd", 'd') << endl;
}