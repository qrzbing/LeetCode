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
    TreeNode *build(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        int m = (l + r) >> 1;
        TreeNode *t = new TreeNode(nums[m]);
        t->left = build(nums, l, m - 1);
        t->right = build(nums, m + 1, r);
        return t;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
