from typing import List


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [0 for i in range(n+1)]
        dp[1] = 1
        dp2 = dp3 = dp5 = 1
        for i in range(2, n + 1):
            n2, n3, n5 = dp[dp2]*2, dp[dp3]*3, dp[dp5]*5
            dp[i] = min(n2, n3, n5)
            if dp[i] == n2:
                dp2 += 1
            if dp[i] == n3:
                dp3 += 1
            if dp[i] == n5:
                dp5 += 1
        return dp[n]


if __name__ == '__main__':
    sol = Solution()
    print(sol.nthUglyNumber(5))
    print(sol.nthUglyNumber(10))
