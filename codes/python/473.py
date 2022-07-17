from typing import List


class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        totalLen = sum(matchsticks)
        if totalLen % 4:
            return False
        edgeLen = totalLen // 4

        dp = [-1] * (1 << len(matchsticks))
        dp[0] = 0

        for s in range(1, len(dp)):
            # s 表示当前的状态，哪位为 1 则说明哪根火柴被放入
            for k, v in enumerate(matchsticks):
                if s & (1 << k) == 0:
                    # 为 0 说明该火柴没有被放入
                    continue
                # 取只有第 k 个火柴没被放入的情况
                s1 = s & ~(1 << k)
                # print(dp)
                # dp[s1] 规则有效且加上第 k 个火柴之后小于边长
                if dp[s1] >= 0 and dp[s1] + v <= edgeLen:
                    dp[s] = (dp[s1] + v) % edgeLen
                    break
        return dp[-1] == 0


if __name__ == '__main__':
    sol = Solution()
    print(sol.makesquare([1, 1, 2, 2, 2]))
    print(sol.makesquare([3, 3, 3, 3, 4]))
    print(sol.makesquare([1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3]))
