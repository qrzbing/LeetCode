#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

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
    bool isSub(TreeNode *nodeA, TreeNode *nodeB)
    {
        if (!nodeB)
        {
            return true;
        }
        if (!nodeA || nodeA->val != nodeB->val)
        {
            return false;
        }
        return isSub(nodeA->left, nodeB->left) && isSub(nodeA->right, nodeB->right);
    }
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        return (A && B) && (isSub(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
};

int main()
{
    TreeNode A1(3), A2(4), A3(5), A4(1), A5(2);
    A1.left = &A2, A1.right = &A3;
    A2.left = &A4, A2.right = &A5;
    TreeNode B1(4), B2(1);
    B1.left = &B2;
    Solution sol;
    sol.isSubStructure(&A1, &B1);
}