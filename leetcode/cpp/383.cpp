#include "global.hpp"

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
            return false;
        int alphabet[27] = {0};
        for (auto ch : magazine)
        {
            ++alphabet[ch - 'a'];
        }
        for (auto ch : ransomNote)
        {
            if (alphabet[ch - 'a'] <= 0)
            {
                return false;
            }
            --alphabet[ch - 'a'];
        }
        return true;
    }
};

int main()
{
    Solution sol;
    sol.canConstruct("a", "b");
}