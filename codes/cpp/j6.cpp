#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> num_stack;
        while (head != NULL)
        {
            num_stack.push(head->val);
            head = head->next;
        }
        vector<int> ret_arr;
        while (!num_stack.empty())
        {
            ret_arr.push_back(num_stack.top());
            num_stack.pop();
        }
        return ret_arr;
    }
};