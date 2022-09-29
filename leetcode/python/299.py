from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0
        sDic = [0]*10
        gDic = [0]*10
        for sch, gch in zip(secret, guess):
            if sch == gch:
                bulls += 1
            else:
                sDic[int(sch)] += 1
                gDic[int(gch)] += 1
        cows = sum(min(s, g) for s, g in zip(sDic, gDic))
        return "{}A{}B".format(bulls, cows)


if __name__ == '__main__':
    sol = Solution()
