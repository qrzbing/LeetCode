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
    vector<int> indorderSeq;

    void getInorder(TreeNode *p)
    {
        if (p->left)
        {
            getInorder(p->left);
        }
        indorderSeq.emplace_back(p->val);
        if (p->right)
        {
            getInorder(p->right);
        }
    }

    TreeNode *build(int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) >> 1;
        TreeNode *tmp = new TreeNode(indorderSeq[mid]);
        // if (mid - 1 >= left)
        tmp->left = build(left, mid - 1);
        // if (mid + 1 <= right)
        tmp->right = build(mid + 1, right);
        return tmp;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        getInorder(root);
        return build(0, indorderSeq.size() - 1);
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
