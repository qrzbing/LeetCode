from typing import List
from collections import defaultdict


class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def split_str(v: str):
            if v == "":
                return 0
            for i, ch in enumerate(v):
                if ch == '.':
                    return i
            return len(v)
        lV1 = len(version1)
        lV2 = len(version2)
        sp1 = version1
        sp2 = version2
        while sp1 != "" or sp2 != "":

            v1 = split_str(sp1)
            v2 = split_str(sp2)
            cmp1 = 0 if v1 == 0 else int(sp1[0:v1])
            cmp2 = 0 if v2 == 0 else int(sp2[0:v2])

            if cmp1 > cmp2:
                return 1
            elif cmp1 < cmp2:
                return -1
            sp1 = sp1[v1+1:] if v1+1 < lV1 else ""
            sp2 = sp2[v2+1:] if v2+1 < lV2 else ""

        return 0


if __name__ == '__main__':
    sol = Solution()
    print(sol.compareVersion("1.01", "1.001"))
    print(sol.compareVersion("1.0", "1.0.0"))
    print(sol.compareVersion("0.1", "1.1"))
    print(sol.compareVersion("1.0.1", "1.1"))
    print(sol.compareVersion("1.0.1", "1"))
