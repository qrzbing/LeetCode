from typing import List


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        l = len(primes)
        ans = [1] + [0 for _ in range(n-1)]
        ptr = [0 for _ in range(l)]
        for i in range(1, n):
            dp = [primes[j] * ans[ptr[j]] for j in range(l)]
            min_num = min(dp)
            ans[i] = min_num
            for j in range(l):
                if dp[j] == min_num:
                    ptr[j] += 1
        return ans[n-1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.nthSuperUglyNumber(12, [2, 7, 13, 19]))
    print(sol.nthSuperUglyNumber(1, [2, 3, 5]))
