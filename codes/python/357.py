from typing import List


class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 10
        for i in range(2, n+1):
            dp[i] = (dp[i-1]-dp[i-2])*(10-i+1) + dp[i-1]
        return dp[n]


if __name__ == '__main__':
    sol = Solution()
    print(sol.countNumbersWithUniqueDigits(2))
    print(sol.countNumbersWithUniqueDigits(3))
    print(sol.countNumbersWithUniqueDigits(4))
