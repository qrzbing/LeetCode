#include "global.hpp"
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *node_fast = head, *node_slow = head;
        while (k--)
        {
            node_fast = node_fast->next;
        }
        while (node_fast)
        {
            node_fast = node_fast->next;
            node_slow = node_slow->next;
        }
        return node_slow;
    }
};