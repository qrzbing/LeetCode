from typing import List
from collections import defaultdict


class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        # defaultdict 可以避免未初始化的键值调用问题
        dp = defaultdict(int)
        k = 0
        # enumerate 可以同时获取索引和值
        for i, ch in enumerate(p):
            # 只有相邻的字母才能 k+=1
            if i > 0 and (ord(ch)-ord(p[i-1])) % 26 == 1:
                k += 1
            else:
                k = 1
            # 更新当前 ch 的最大子串数量
            dp[ch] = max(dp[ch], k)
        return sum(dp.values())


if __name__ == '__main__':
    sol = Solution()
