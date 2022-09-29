from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def getHash(word: str):
            ret = 0
            for ch in word:
                num = ord(ch) - ord('a')
                ret = (1 << num) | ret
            return ret
        hashes = [getHash(x) for x in words]
        l = len(hashes)
        maxLen = 0
        for i in range(l):
            for j in range(i+1, l):
                if hashes[i] & hashes[j] == 0:
                    maxLen = max(maxLen, len(words[i])*len(words[j]))
        return maxLen


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxProduct(["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]))
    print(sol.maxProduct(["a", "ab", "abc", "d", "cd", "bcd", "abcd"]))
    print(sol.maxProduct(["a", "aa", "aaa", "aaaa"]))
