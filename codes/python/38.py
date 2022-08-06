from typing import List
from collections import defaultdict


class Solution:

    def countAndSay(self, n: int) -> str:
        ret = ["", "1"]

        def countNum(s: str) -> str:
            retstr = ""
            if len(s) == 0:
                return ""
            cur = s[0]
            cnt = 1
            for i, ch in enumerate(s):
                if i == 0:
                    continue
                if ch != cur:
                    retstr = retstr + ("{}{}".format(cnt, cur))
                    cur = ch
                    cnt = 1
                else:
                    cnt += 1
            retstr += ("{}{}".format(cnt, cur))
            return retstr



        for i in range(2, n+1):
            ret.append(countNum(ret[i-1]))
        # print(ret)
        return ret[n]


if __name__ == '__main__':
    sol = Solution()
    print(sol.countAndSay(3))
    print(sol.countAndSay(30))
