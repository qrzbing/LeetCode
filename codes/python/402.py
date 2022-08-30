from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stk = []
        for ch in num:
            # print(ch, stk, k)
            if stk == []:
                stk.append(ord(ch)-ord('0'))
                continue
            curNum = ord(ch)-ord('0')
            while k > 0 and stk != [] and stk[len(stk)-1] > curNum:
                stk.pop()
                k -= 1
            stk.append(curNum)
        for _ in range(k, 0, -1):
            if stk != []:
                stk.pop()
        ret = "".join([str(num) for num in stk]).lstrip("0")
        return "0" if ret == "" else ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.removeKdigits("1432219", 3))
    print(sol.removeKdigits("10200", 1))
    print(sol.removeKdigits("10", 2))
    print(sol.removeKdigits("10", 1))
    print(sol.removeKdigits("1234567890", 9))
