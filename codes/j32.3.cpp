#include <vector>
#include <queue>
#include <stack>
#include <deque>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        deque<TreeNode *> dt;
        vector<vector<int>> vvi;
        bool ltr = true;
        if (root)
        {
            dt.push_back(root);
        }
        else
        {
            return vvi;
        }
        while (!dt.empty())
        {
            vector<int> vi;
            if (ltr)
            {
                ltr = !ltr;
                int i = dt.size();
                while (i--)
                {
                    vi.push_back(dt.front()->val);
                    if (dt.front()->left)
                        dt.push_back(dt.front()->left);
                    if (dt.front()->right)
                        dt.push_back(dt.front()->right);
                    dt.pop_front();
                }
            }
            else
            {
                ltr = !ltr;
                int i = dt.size();
                while (i--)
                {
                    vi.push_back(dt.back()->val);
                    if (dt.back()->right)
                        dt.push_front(dt.back()->right);
                    if (dt.back()->left)
                        dt.push_front(dt.back()->left);
                    dt.pop_back();
                }
            }
            vvi.push_back(vi);
        }
        return vvi;
    }
};