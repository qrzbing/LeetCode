from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def decodeString(self, s: str) -> str:
        idx = 0

        def getString():
            nonlocal idx
            if idx == len(s) or s[idx] == ']':
                return ""
            cur = s[idx]
            repeatTime = 1
            ret = ""
            if cur.isdigit():
                repeatTime = getDigit()
                idx += 1
                repeatStr = getString()
                idx += 1
                for _ in range(repeatTime):
                    ret += repeatStr
            elif cur.isalpha():
                ret = cur
                idx += 1
            return ret + getString()

        def getDigit():
            nonlocal idx
            ret = 0
            while idx < len(s) and s[idx].isdigit():
                ret = ret * 10 + ord(s[idx]) - ord('0')
                idx += 1
            return ret

        return getString()


if __name__ == '__main__':
    sol = Solution()
    print(sol.decodeString("3[a]2[bc]"))
    print(sol.decodeString("3[a2[c]]"))
