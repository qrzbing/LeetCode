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
    vector<TreeNode *> gt(int start, int end)
    {
        if (start > end)
            return {nullptr};
        vector<TreeNode *> ret;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left = gt(start, i - 1);
            vector<TreeNode *> right = gt(i + 1, end);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *t = new TreeNode(i, l, r);
                    ret.emplace_back(t);
                }
            }
        }
        return ret;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return gt(1, n);
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
