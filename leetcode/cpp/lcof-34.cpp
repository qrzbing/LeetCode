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
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode *node, int target)
    {
        if (!node)
        {
            return;
        }
        path.emplace_back(node->val);
        target -= node->val;
        if (!target && !node->left && !node->right)
        {
            ret.emplace_back(path);
        }
        dfs(node->left, target);
        dfs(node->right, target);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        dfs(root, target);
        return ret;
    }
};