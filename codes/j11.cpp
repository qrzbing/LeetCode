#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {

            int m = (l + r) / 2;
            if (numbers[m] > numbers[r])
            {
                l = m + 1;
            }
            else if (numbers[m] < numbers[r])
            {
                r = m;
            }
            else
            {
                r--;
            }
        }
        return numbers[r];
    }
};

int main()
{
    vector<int> test = {3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.minArray(test) << "\n";
}