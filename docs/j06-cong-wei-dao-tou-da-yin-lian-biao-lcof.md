# 剑指 Offer 06. 从尾到头打印链表

Difficulty: Easy
Language: C++
Link: https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
No: 6
Status: Done
Tags: 链表

我用了一个栈保存数据

-----
```cpp
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
```

题解有一些人写的还挺有意思，可以递归（这个方法我觉得不大行）、反转链表等。