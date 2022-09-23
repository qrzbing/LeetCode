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
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        x = None
        y = None
        pre = None
        def dfs(node):
            nonlocal pre, x, y
            if node == None:
                return
            dfs(node.left)
            if pre and pre.val > node.val:
                if not x:
                    x = pre
                # 记录最后一个需要调换的位置
                y = node
            pre = node
            dfs(node.right)

        dfs(root)
        x.val, y.val = y.val, x.val


if __name__ == '__main__':
    sol = Solution()
