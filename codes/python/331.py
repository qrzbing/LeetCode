from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        preorder = preorder.split(",")
        cnt = 1
        for leaf in preorder:
            if leaf != '#':
                if cnt == 0:
                    return False
                cnt -= 1
                cnt += 2
            else:
                if cnt == 0:
                    return False
                cnt -= 1
        return cnt == 0


if __name__ == '__main__':
    sol = Solution()
    print(sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"))
    print(sol.isValidSerialization("1,#"))
    print(sol.isValidSerialization("9,#,#,1"))
    print(sol.isValidSerialization("#,#"))
    print(sol.isValidSerialization("#,7,6,9,#,#,#"))
