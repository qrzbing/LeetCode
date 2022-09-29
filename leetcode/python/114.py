from typing import List, Optional
from collections import defaultdict, Counter
from functools import cmp_to_key

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        lst = []
        def dfs(node):
            if not node:
                return
            lst.append(node)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        # print(lst)
        for i in range(1, len(lst)):
            lst[i-1].left = None
            lst[i-1].right = lst[i]



if __name__ == '__main__':
    sol = Solution()
    root = TreeNode(1, TreeNode(2, TreeNode(3), TreeNode(4)), TreeNode(5, None, TreeNode(6)))
    sol.flatten(root)
