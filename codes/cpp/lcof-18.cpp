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
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *tmp = head;
        ListNode *ptr_pre = nullptr;
        while (tmp)
        {
            if (tmp->val == val)
            {
                if (tmp == head)
                {
                    head = head->next;
                    return head;
                }
                ptr_pre->next = tmp->next;
            }
            ptr_pre = tmp;
            tmp = tmp->next;
        }
        return head;
    }
};