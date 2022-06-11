from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        l = len(nums)
        dp = [1]*l
        nums.sort()
        max_ss = 1
        for i in range(1, l):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[i] <= dp[j]:
                        dp[i] = dp[j] + 1
                        max_ss = max(max_ss, dp[i])
        # print(max_ss)
        last = 0
        ret = []
        for i in range(l-1, -1, -1):
            if max_ss == dp[i]:
                if last == 0:
                    ret.append(nums[i])
                elif last % nums[i] == 0:
                    ret.append(nums[i])
                else:
                    continue
                last = nums[i]
                max_ss -= 1
                if max_ss < 0:
                    break
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.largestDivisibleSubset([1, 2, 3]))
    print(sol.largestDivisibleSubset([1, 2, 4, 8]))
    print(sol.largestDivisibleSubset([1, 2, 3, 4, 6, 8]))
    print(sol.largestDivisibleSubset([1]))
