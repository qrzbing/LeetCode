from ast import Str
from typing import List


class Solution:
    def hasGcd(self, n: int) -> List[str]:
        def gcd(a: int, b: int) -> int: return (gcd(b, a % b) if a % b else b)
        ret = []
        for i in range(2, n):
            if gcd(n, i) != 1:
                ret.append(i)
        return ret

    def simplifiedFractions(self, n: int) -> List[str]:
        ret = []
        gcdList = {}
        for i in range(1, n+1):
            for j in range(i+1, n+1, i):
                if j not in gcdList:
                    gcdList[j] = self.hasGcd(j)
                for k in range(j, i+j):
                    if k < n+1 and i not in gcdList[k]:
                        ret.append("{}/{}".format(i, k))
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.simplifiedFractions(100))
