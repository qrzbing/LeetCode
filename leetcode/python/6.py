from typing import List
from collections import defaultdict


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        lines = ["" for _ in range(numRows)]
        mod = numRows * 2 - 2
        for i, ch in enumerate(s):
            l = i % mod
            if l < numRows:
                lines[l]+=ch
            else:
                lines[numRows-1-(l-numRows+1)]+=ch
        # print(lines)
        return "".join(lines)


if __name__ == '__main__':
    sol = Solution()
    print(sol.convert("PAYPALISHIRING", 3))
    print(sol.convert("PAYPALISHIRING", 4))
    print(sol.convert("A", 1))
