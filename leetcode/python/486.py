from typing import List
from collections import defaultdict


class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        nLen = len(nums)
        dp = [[0]*nLen for _ in range(nLen)]
        for i, num in enumerate(nums):
            dp[i][i] = num
        for i in range(nLen-2, -1, -1):
            for j in range(i+1, nLen):
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])
        return dp[0][nLen-1] >= 0


if __name__ == '__main__':
    sol = Solution()
    print(sol.PredictTheWinner([1, 5, 2]))
    print(sol.PredictTheWinner([1, 5, 233, 7]))
