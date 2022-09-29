from operator import truediv
from typing import List, Optional
from collections import defaultdict
from functools import cmp_to_key

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        pre = float('-inf')
        def dfs(node) -> bool:
            nonlocal pre
            if node == None:
                return True
            if dfs(node.left) is False:
                return False
            if node.val <= pre:
                return False
            pre = node.val
            if dfs(node.right) is False:
                return False
            return True

        return dfs(root)


if __name__ == '__main__':
    sol = Solution()
