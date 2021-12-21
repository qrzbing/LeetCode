#include "global.hpp"

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

public:
    int kthLargest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;
        TreeNode *tmp = root;
        while (tmp || !st.empty())
        {
            while (tmp)
            {
                st.push(tmp);
                tmp = tmp->right;
            }
            if (!st.empty())
            {
                tmp = st.top();
                k--;
                if (!k)
                    return tmp->val;
                st.pop();
                tmp = tmp->left;
            }
        }
        return 0;
    }
};