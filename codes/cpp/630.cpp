#include "global.hpp"

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [this](vector<int> &l, vector<int> &r)
             { return l.at(1) < r.at(1); });
        int curr_time = 0;
        priority_queue<int> q;
        for (vector<int> &course : courses)
        {
            int ti = course.at(0), di = course.at(1);
            if (curr_time + ti <= di)
            {
                curr_time = curr_time + ti;
                q.push(ti);
            }
            else if (!q.empty() && q.top() > ti)
            {
                curr_time -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }
        return q.size();
    }
};

/*
Line 12: Char 46: error: reference to non-static member function must be called
        sort(courses.begin(), courses.end(), cmp);
                                             ^~~
1 error generated.
*/
// https://stackoverflow.com/questions/1902311/problem-sorting-using-member-function-as-comparator

int main()
{
}

// [[5,5],[4,6],[2,6]] 2