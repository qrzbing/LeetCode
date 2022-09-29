from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        def cmpDict(a, b):
            a = ord(a) - ord('a')
            b = ord(b) - ord('a')
            if a == b:
                return 0
            return 1 if a > b else -1
        ret = []
        for i, ch in enumerate(s):
            if ret == []:
                ret.append(ch)
                continue
            if ch in ret:
                continue
            l = len(ret)
            l2 = 0
            while len(ret) > 0 and l != l2:
                # print(ret)
                l = len(ret)
                lastCh = ret[len(ret)-1]
                if cmpDict(ch, lastCh) < 0 and lastCh in s[i+1:]:
                    ret.pop()
                l2 = len(ret)
            ret.append(ch)

        return "".join(ret)


if __name__ == '__main__':
    sol = Solution()
    print(sol.removeDuplicateLetters("bcabc"))
    print(sol.removeDuplicateLetters("cbacdcbc"))
