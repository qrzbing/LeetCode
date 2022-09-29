#include "global.hpp"

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sc;
        for (char ch : s)
        {
            switch (ch)
            {
            case '(':
                sc.push('(');
                break;
            case '[':
                sc.push('[');
                break;
            case '{':
                sc.push('{');
                break;
            case ')':
                if (sc.empty() || sc.top() != '(')
                    return false;
                sc.pop();
                break;
            case ']':
                if (sc.empty() || sc.top() != '[')
                    return false;
                sc.pop();
                break;
            case '}':
                if (sc.empty() || sc.top() != '{')
                    return false;
                sc.pop();
                break;

            default:
                break;
            }
        }
        if (!sc.empty())
            return false;
        return true;
    }
};

int main()
{
    Solution sol;
    cout << (sol.isValid("([)]") ? "true\n" : "false\n");
    cout << (sol.isValid("{[]}") ? "true\n" : "false\n");
}