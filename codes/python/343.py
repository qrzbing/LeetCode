from typing import List


class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [1] * (n+1)
        for i in range(2, n+1):
            for j in  range(1, i):
                dp[i] = max((i-j)*j, dp[i-j]*j, dp[i])
        return dp[n]

if __name__ == '__main__':
    sol = Solution()
    print(sol.integerBreak(10))
    print(sol.integerBreak(2))
