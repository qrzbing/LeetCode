#include <vector>
#include <queue>
using namespace std;

//Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> qt;
        vector<vector<int>> ret;

        if (root)
            qt.push(root);
        else
            return ret;

        while (!qt.empty())
        {
            vector<int> vi;
            int i = qt.size();
            while (i--)
            {
                vi.push_back(qt.front()->val);
                if (qt.front()->left)
                    qt.push(qt.front()->left);
                if (qt.front()->right)
                    qt.push(qt.front()->right);
                qt.pop();
            }
            ret.push_back(vi);
        }

        return ret;
    }
};