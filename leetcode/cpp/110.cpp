#include "global.hpp"

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int preOrder(TreeNode *n)
    {
        if (!n)
            return 0;
        int l = preOrder(n->left);
        int r = preOrder(n->right);
        if (l != -1 && r != -1 && abs(l - r) <= 1)
        {
            return max(l, r) + 1;
        }
        return -1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return preOrder(root) != -1;
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
