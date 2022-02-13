#include "global.hpp"

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> vc(5);
        for (char ch : text)
        {
            switch (ch)
            {
            case 'b':
                vc[0]++;
                break;
            case 'a':
                vc[1]++;
                break;
            case 'l':
                vc[2]++;
                break;
            case 'o':
                vc[3]++;
                break;
            case 'n':
                vc[4]++;
                break;
            default:
                break;
            }
        }
        vc[2] /= 2;
        vc[3] /= 2;
        return *min_element(vc.begin(), vc.end());
    }
};

int main()
{
    Solution sol;

    return 0;
}
