from typing import List, Optional
from collections import defaultdict, Counter, deque
from functools import cmp_to_key


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        l = len(nums)
        if l < 3:
            return []
        nums.sort()
        ret = []
        for i in range(l):
            if nums[i] > 0:
                return ret
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j = i+1
            k = l-1
            while j < k:
                n_sum = nums[i]+nums[j]+nums[k]
                if n_sum == 0:
                    ret.append([nums[i], nums[j], nums[k]])
                    while j<k and nums[j]==nums[j+1]:
                        j=j+1
                    while j<k and nums[k]==nums[k-1]:
                        k=k-1
                    j=j+1
                    k=k-1
                elif n_sum >= 0:
                    k=k-1
                else:
                    j=j+1
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.threeSum([-1,0,1,2,-1,-4]))
