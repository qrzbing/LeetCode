from typing import List
from collections import defaultdict


class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        sLen = len(strs)
        dp = [[[0 for _ in range(n+1)]
               for _ in range(m+1)]
              for _ in range(sLen+1)]
        for i in range(1, sLen+1):          # 第一层循环：字符串（物品）
            c0 = strs[i-1].count('0')       # 当前字符串中 0 的数量
            c1 = len(strs[i-1])-c0          # 当前字符串中 1 的数量
            for j in range(m+1):            # 第二层循环：0 的背包容量
                for k in range(n+1):        # 第三层循环：1 的背包容量
                    if j < c0 or k < c1:    # 无法添加当前字符串
                        dp[i][j][k] = dp[i-1][j][k]
                    else:                   # 可选可不选，就添加最大的情况
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-c0][k-c1]+1)
                    # print(dp)
        return dp[sLen][m][n]


if __name__ == '__main__':
    sol = Solution()
    print(sol.findMaxForm(["10", "0001", "111001", "1", "0"], 5, 3))
    print(sol.findMaxForm(["10", "0", "1"], 1, 1))
