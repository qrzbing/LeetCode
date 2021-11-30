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
    bool checkNode(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr && B == nullptr)
        {
            return true;
        }
        else if (A != nullptr && B != nullptr)
        {
            if (A->val != B->val)
            {
                return false;
            }
            return checkNode(A->left, B->right) && checkNode(A->right, B->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            return checkNode(root->left, root->right);
        }
        return true;
    }
};