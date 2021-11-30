#include <iostream>
#include <stack>
using namespace std;

class CQueue
{
    stack<int> st1;
    stack<int> st2;

public:
    CQueue()
    {
        while (!st1.empty())
            st1.pop();
        while (!st2.empty())
            st2.pop();
    }

    void appendTail(int value)
    {
        st1.push(value);
    }

    int deleteHead()
    {
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty())
        {
            return -1;
        }
        int ret = st2.top();
        st2.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */