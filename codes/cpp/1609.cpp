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
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> qt;
        qt.push(root);
        int line = 0;
        int odd = 0, even = 0x7fffffff;
        int num = 1, i = 0, next_num = 0;
        while (!qt.empty())
        {
            TreeNode *tmp = qt.front();
            qt.pop();
            if (i == num)
            {
                odd = 0, even = 0x7fffffff;
                line++;
                num = next_num;
                next_num = 0;
                i = 0;
            }
            if (!(line & 1) && (tmp->val & 1) && tmp->val > odd)
                odd = tmp->val;
            else if ((line & 1) && !(tmp->val & 1) && tmp->val < even)
                even = tmp->val;
            else
                return false;
            i++;
            if (tmp->left)
                qt.push(tmp->left), next_num++;
            if (tmp->right)
                qt.push(tmp->right), next_num++;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    TreeNode l2_0(3), l2_1(3), l2_2(7);
    TreeNode l1_0(4, &l2_0, &l2_1), l1_1(2, &l2_2, nullptr);
    TreeNode l0_0(5, &l1_0, &l1_1);
    cout << sol.isEvenOddTree(&l0_0) << "\n";
}
