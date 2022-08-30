from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) < k:
            return 0
        for ch in set(s):
            if s.count(ch) < k:
                return max(self.longestSubstring(subStr, k) for subStr in s.split(ch))
        return len(s)

if __name__ == '__main__':
    sol = Solution()
