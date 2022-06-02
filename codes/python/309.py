from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        l = len(prices)
        dp0, dp1, dp2 = -prices[0], 0, 0
        for i in range(1, l):
            dpn0 = max(dp0, dp2-prices[i])
            dpn1 = dp0+prices[i]
            dpn2 = max(dp1, dp2)
            dp0, dp1, dp2 = dpn0, dpn1, dpn2

        return max(dp1, dp2)


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxProfit([7, 1, 5, 3, 6, 4]))
    print(sol.maxProfit([1, 2, 3, 4, 5]))
    print(sol.maxProfit([7, 6, 4, 3, 1]))
    print(sol.maxProfit([1, 2, 3, 0, 2]))
