from typing import List
from functools import cache


class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        @cache
        def dfs(usedNumbers: int, currentTotal: int) -> bool:
            # 遍历所有可能情况
            for i in range(maxChoosableInteger):
                # 数字没用过
                if (usedNumbers >> i) & 1 == 0:
                    # 赢的两种情况
                    # 1. 加上当前数字的和大于 desiredTotal
                    # 2. DFS 后第二个人也赢不了
                    if currentTotal + i + 1 >= desiredTotal or \
                            not dfs(usedNumbers | (1 << i), currentTotal+i+1):
                        return True
            return False
        # 返回的两种情况
        # 1. 选取了所有数字之后都不能达到目标数值
        # 2. 遍历所有选取情况
        return (1+maxChoosableInteger)*maxChoosableInteger//2 >= desiredTotal and dfs(0, 0)


if __name__ == '__main__':
    sol = Solution()
    print(sol.canIWin(10, 1))
    print(sol.canIWin(18, 79))
