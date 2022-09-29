from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def specialSort(num1, num2):
            n1 = str(num1)
            n2 = str(num2)
            # print(n1+n2, n2+n1)
            if int(n1+n2) > int(n2+n1):
                return -1
            else:
                return 1
        nums.sort(key=cmp_to_key(specialSort))
        ret = "".join(str(num) for num in nums)
        for i, ch in enumerate(ret):
            if ch != "0":
                return ret[i:]
        return "0"


if __name__ == '__main__':
    sol = Solution()
    print(sol.largestNumber([4, 42, 45]))
    print(sol.largestNumber([10, 2]))
    print(sol.largestNumber([3, 30, 34, 5, 9]))
    print(sol.largestNumber([34323, 3432]))
    print(sol.largestNumber([0, 0]))
