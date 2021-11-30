#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> min_st;
    MinStack()
    {
        while (!st.empty())
            st.pop();
        while (!min_st.empty())
            min_st.pop();
    }

    void push(int x)
    {
        st.push(x);
        if (min_st.empty())
        {
            min_st.push(x);
        }
        else
        {
            if (x <= min_st.top())
            {
                min_st.push(x);
            }
        }
    }

    void pop()
    {
        if (st.top() == min_st.top())
        {
            min_st.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int min()
    {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
int main()
{
    MinStack test = MinStack();
    test.push(-2);
    test.push(0);
    test.push(-3);
    cout << test.min() << "\n";
    test.pop();
    cout << test.top() << "\n";
    cout << test.min() << "\n";
}