from audioop import reverse
from typing import List


class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        ret = []
        l = len(arr)
        for i in range(l, 1, -1):
            index = 0
            for j in range(i):
                if arr[j] > arr[index]:
                    index = j
            if index != i-1:
                if index != 0:
                    ret.append(index+1)
                ret.append(i)
                for k in range((index+1)//2):
                    arr[k], arr[index-k] = arr[index-k], arr[k]
                for k in range((i+1)//2):
                    arr[k], arr[i-k-1] = arr[i-k-1], arr[k]
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.pancakeSort([3, 2, 4, 1]))
    print(sol.pancakeSort([1, 2, 3]))
    print(sol.pancakeSort([3, 2, 1, 4]))
