#include "global.hpp"

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ret = nullptr;
        ListNode *t = ret;
        ListNode *begin = head;
        ListNode *end = begin->next;
        vector<int> sss;
        while (true)
        {
            int sum = 0;
            while (end != nullptr)
            {
                if (end->val == 0)
                {
                    begin = end;
                    end = end->next;
                    break;
                }
                else
                {
                    sum += end->val;
                    end = end->next;
                }
            }
            if (sum == 0)
                break;
            sss.emplace_back(sum);
        }
        for (int num : sss)
        {
            if (ret == nullptr)
            {
                ret = new ListNode(num);
                t = ret;
            }
            else
            {
                t->next = new ListNode(num);
                t = t->next;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    ListNode v1(0);
    ListNode v2(2, &v1);
    ListNode v3(5, &v2), v4(4, &v3), v5(0, &v2), v6(1, &v5), v7(3, &v6), v8(0, &v7);
    ListNode *l = sol.mergeNodes(&v8);
    while (l != nullptr)
    {
        cout << l->val << endl;
        l = l->next;
    }
    return 0;
}
