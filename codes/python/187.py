from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        l = len(s)
        diffDict = {}
        for i in range(l-9):
            splitStr = s[i:i+10]
            if splitStr not in diffDict:
                diffDict[splitStr] = 1
            else:
                diffDict[splitStr] += 1
        ret = []
        for key in diffDict:
            if diffDict[key] > 1:
                ret.append(key)
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
    print(sol.findRepeatedDnaSequences("AAAAAAAAAAAAA"))
