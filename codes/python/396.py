from typing import List


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        l = len(nums)
        summary = sum(nums)
        dp = [0]*l
        # Calculate F(0)
        for i in range(l):
            dp[0] += i*nums[i]
        ret = dp[0]
        for i in range(1, l):
            dp[i]=dp[i-1]+summary-l*nums[l-i]
            ret = max(ret, dp[i])
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxRotateFunction([4,3,2,6]))
