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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ha = headA, *hb = headB;
        while (ha != hb)
        {
            ha = ha ? ha->next : headB;
            hb = hb ? hb->next : headA;
        }
        return ha;
    }
};