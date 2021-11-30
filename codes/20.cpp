
// Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *lh = nullptr, *lm = nullptr;
    int inc = 0;
    while (l1 || l2)
    {
        ListNode *lt = new ListNode;
        if (!lh)
        {
            lh = lt;
            lm = lt;
        }
        else
        {
            lm->next = lt;
            lm = lt;
        }
        lm->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + inc;
        inc = 0;
        if (lm->val > 10)
        {
            lm->val -= 10;
            inc = 1;
        }
        if (l1)
            l1 = l1->next;
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if (inc)
    {
        ListNode *lt = new ListNode;
        lt->val = 1;
        lm->next = lt;
    }
    else
    {
        lm->next = nullptr;
    }
    return lh;
}

int main()
{
    ListNode *t1 = new ListNode;
    ListNode *t2 = new ListNode;
    t1->val = 7, t1->next = nullptr;
    t2->val = 7, t2->next = nullptr;
    ListNode *t3 = addTwoNumbers(t1, t2);
    while (t3 != nullptr)
    {
        cout << t3->val << " ";
        t3 = t3->next;
    }
}