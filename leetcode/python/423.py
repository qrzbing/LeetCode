from typing import List
from collections import defaultdict, Counter
from functools import cmp_to_key


class Solution:
    def originalDigits(self, s: str) -> str:
        c = Counter(s)
        cnt = [0] * 10
        cnt[0] = c['z']
        cnt[6] = c['x']
        cnt[2] = c['w']
        cnt[4] = c['u']
        cnt[8] = c['g']
        cnt[7] = c['s'] - cnt[6]
        cnt[3] = c['h'] - cnt[8]
        cnt[5] = c['f'] - cnt[4]
        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8]
        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4]
        return "".join([str(i) * cnt[i] for i in range(10)])


if __name__ == '__main__':
    sol = Solution()
