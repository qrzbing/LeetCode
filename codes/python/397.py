from typing import List

class Solution:
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0
        if n % 2 == 0:
            n = n / 2
            return self.integerReplacement(n)+1
        else:
            return min(self.integerReplacement(n+1), self.integerReplacement(n-1))+1


if __name__ == '__main__':
    sol = Solution()
    print(sol.integerReplacement(pow(2, 31)-5))
