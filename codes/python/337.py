from typing import List

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def robbing(self, t: TreeNode):
        if t is None:
            return 0, 0
        left_l, left_r = self.robbing(t.left)
        right_l, right_r = self.robbing(t.right)
        return max(left_l+right_l, left_r+right_r+t.val), max(left_l+right_l, left_r+right_r)

    def rob(self, root: TreeNode) -> int:
        if root is None:
            return 0
        ret, _ = self.robbing(root)
        return ret


if __name__ == '__main__':
    sol = Solution()
    t = TreeNode(3, TreeNode(2, None, TreeNode(3)), TreeNode(3, None, TreeNode(1)))
    print(sol.rob(t))
    t = TreeNode(3, TreeNode(4, TreeNode(1), TreeNode(3)), TreeNode(5, None, TreeNode(1)))
    print(sol.rob(t))
