from typing import List
from collections import defaultdict


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[""]] # dp[0] = [[""]]
        for i in range(1, n+1):
            dpi = []
            for p in range(i):
                q = i-1-p
                for parep in dp[p]:
                    for pareq in dp[q]:
                        dpi.append("({}){}".format(parep, pareq))
            dp.append(dpi)
        return dp[n]


            


if __name__ == '__main__':
    sol = Solution()
    print(sol.generateParenthesis(3))
