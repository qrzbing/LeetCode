#include <iostream>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{

public:
    Node *copyRandomList(Node *head)
    {
        // First time to loop
        Node *tmpNode = head;
        while (tmpNode)
        {
            Node *newNode = new Node(tmpNode->val);
            newNode->next = tmpNode->next;
            newNode->random = tmpNode->random;
            tmpNode->next = newNode;
            tmpNode = newNode->next;
            // newNode head = head->next;
        }
        // Second time to loop
        tmpNode = head;
        Node *retNode = head ? head->next : nullptr;
        while (tmpNode)
        {
            // for each loop skip 2 nodes
            // tmpNode->next->next = tmpNode->next->next ? tmpNode->next->next->next : nullptr;
            if (tmpNode->random)
                tmpNode->next->random = tmpNode->next->random->next;
            tmpNode = tmpNode->next->next;
        }
        // recover list
        tmpNode = head;
        while (tmpNode)
        {
            Node *nextNode = tmpNode->next->next;
            tmpNode->next->next = tmpNode->next->next ? tmpNode->next->next->next : nullptr;
            tmpNode->next = nextNode;
            tmpNode = nextNode;
        }
        return retNode;
    }
};

int main()
{
    Node a1(7), a2(13), a3(11), a4(10), a5(1);
    a1.next = &a2, a1.random = nullptr;
    a2.next = &a3, a2.random = &a1;
    a3.next = &a4, a3.random = &a5;
    a4.next = &a5, a4.random = &a3;
    a5.next = nullptr, a5.random = &a1;
    Solution sol;
    sol.copyRandomList(&a1);
}