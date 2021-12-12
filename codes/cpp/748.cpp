#include "global.hpp"

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        array<int, 26> lp = {0};
        string ret;
        for (char ch : licensePlate)
            if (ch >= 'a' && ch <= 'z')
                ++lp[ch - 'a'];
            else if (ch >= 'A' && ch <= 'Z')
                ++lp[ch - 'A'];
        int minSize = 1001;
        for (string &word : words)
        {
            int size = word.length();
            array<int, 26> wda = {0};
            for (char ch : word)
                ++wda[ch - 'a'];
            bool satisfy = true;
            for (int i = 0; i < 26; ++i)
                if (wda[i] < lp[i])
                {
                    satisfy = false;
                    break;
                }
            if (satisfy && size < minSize)
            {
                ret = word;
                minSize = size;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> vs = {"step", "steps", "stripe", "stepple"};
    cout << sol.shortestCompletingWord("1s3 PSt", vs) << endl;

    vs = {"looks", "pest", "stew", "show"};
    cout << sol.shortestCompletingWord("1s3 456", vs) << endl;

    vs = {"suggest", "letter", "of", "husband", "easy", "education", "drug", "prevent", "writer", "old"};
    cout << sol.shortestCompletingWord("Ah71752", vs) << endl;

    vs = {"enough", "these", "play", "wide", "wonder", "box", "arrive", "money", "tax", "thus"};
    cout << sol.shortestCompletingWord("OgEu755", vs) << endl;

    vs = {"claim", "consumer", "student", "camera", "public", "never", "wonder", "simple", "thought", "use"};
    cout << sol.shortestCompletingWord("iMSlpe4", vs) << endl;

    return 0;
}