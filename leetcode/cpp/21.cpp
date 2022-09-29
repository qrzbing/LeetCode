class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ret = nullptr;
        ListNode *tmp;
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        while (list1 && list2)
        {
            if (!ret)
            {
                if (list1->val > list2->val)
                {
                    ret = list2;
                    list2 = list2->next;
                }
                else
                {
                    ret = list1;
                    list1 = list1->next;
                }
                tmp = ret;
                continue;
            }
            if (list1->val > list2->val)
            {
                tmp->next = list2;
                list2 = list2->next;
            }
            else
            {
                tmp->next = list1;
                list1 = list1->next;
            }
            tmp = tmp->next;
        }
        if (list1)
            tmp->next = list1;
        if (list2)
            tmp->next = list2;
        return ret;
    }
};