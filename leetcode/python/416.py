from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        # 初始化及几种不可解情况
        summary = sum(nums)
        if summary & 1 == 1:
            return False
        target = summary >> 1
        if max(nums) > target:
            return False
        n = len(nums)
        if n < 2:
            return False

        dp = [[False for _ in range(target+1)] for _ in range(n)]

        # 边界情况
        for i in range(n):
            dp[i][0] = True
        dp[0][nums[0]] = True

        # 其他情况
        for i in range(1, n):
            for j in range(1, target+1):
                if j < nums[i]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i]]

        return dp[n-1][target]


if __name__ == '__main__':
    sol = Solution()
    print(sol.canPartition([1, 5, 11, 5]))
    print(sol.canPartition([1, 2, 3, 5]))
    print(sol.canPartition([100]))
