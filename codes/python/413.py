from typing import List


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        l = len(nums)
        c = 0
        ret = 0
        for i in range(1, l-1):
            if nums[i]-nums[i-1] == nums[i+1]-nums[i]:
                c += 1
                ret += c
            else:
                c = 0
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.numberOfArithmeticSlices([1,2,3,4,5,6]))
    print(sol.numberOfArithmeticSlices([1,2,3,4]))
    print(sol.numberOfArithmeticSlices([1, 2, 3, 4, 5, 19, 20, 30, 40]))
