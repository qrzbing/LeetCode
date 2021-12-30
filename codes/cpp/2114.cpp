#include "global.hpp"

class Solution
{
public:
    int retSentenceWords(string &sentence)
    {
        int ret = 0;
        for (char ch : sentence)
        {
            if (ch == ' ')
            {
                ret++;
            }
        }
        return ret + 1;
    }
    int mostWordsFound(vector<string> &sentences)
    {
        int ret = 0;
        for (string &s : sentences)
        {
            ret = max(ret, retSentenceWords(s));
        }
        return ret;
    }
};