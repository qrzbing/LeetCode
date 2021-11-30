#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *newhead = reverseList(head);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};

void printList(ListNode *l)
{
    while (l)
    {
        cout << l->val << "\n";
        l = l->next;
    }
}

int main()
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr;
    printList(&n1);
}