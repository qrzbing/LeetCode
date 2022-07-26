from typing import List
from collections import defaultdict


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def myQuickSort(l: int, r: int) -> int:
            def partition(l: int, r: int) -> int:
                pivot = l
                index = l+1
                for i in range(l+1, r+1):
                    if nums[pivot] < nums[i]:
                        nums[index], nums[i] = nums[i], nums[index]
                        # print(nums[l:r-l+1])
                        index += 1
                nums[index-1], nums[pivot] = nums[pivot], nums[index-1]
                return index-1
            if l <= r:
                pIdx = partition(l, r)
                # print(pIdx)
                if pIdx+1<k:
                    return myQuickSort(pIdx+1, r)
                elif pIdx+1>k:
                    return myQuickSort(l, pIdx)
                else:
                    return nums[pIdx]
        numsLen = len(nums)
        return myQuickSort(0, numsLen-1)


if __name__ == '__main__':
    sol = Solution()
    print(sol.findKthLargest([3, 2, 1, 5, 6, 4], 2))
    print(sol.findKthLargest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))
    print(sol.findKthLargest([1], 1))
    print(sol.findKthLargest([2,1], 2))
