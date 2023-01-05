from typing import List, Optional
from collections import defaultdict, Counter, deque
from functools import cmp_to_key


class Solution:
    def maxArea(self, height: List[int]) -> int:
        j = len(height)-1
        i = 0
        ret = 0
        while i < j:
            ret = max((j-i)*min(height[i], height[j]), ret)
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
