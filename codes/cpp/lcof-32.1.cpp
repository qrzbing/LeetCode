#include <vector>
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
    vector<int> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> qt;
        vector<int> ret;
        if (root)
            qt.push(root);
        while (!qt.empty())
        {
            ret.push_back(qt.front()->val);
            if (qt.front()->left)
            {
                qt.push(qt.front()->left);
            }
            if (qt.front()->right)
            {
                qt.push(qt.front()->right);
            }
            qt.pop();
        }
        return ret;
    }
};