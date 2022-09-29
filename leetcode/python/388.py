from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def lengthLongestPath(self, input: str) -> int:
        idx = 0
        tCnt = 0
        stk = []
        s = ""
        ret = 0
        for i, ch in enumerate(input):
            if ch == '\n' or i == len(input)-1:
                s = input[idx:i].strip("\n\t") if ch == '\n' else input[idx:i+1].strip("\n\t")
                l = len(stk) # 当前路径
                # print(tCnt, stk)
                if tCnt <= l-1:
                    for _ in range(l, tCnt, -1):
                        stk.pop()
                stk.append(s)
                if "." in s:
                    ret = max(ret, sum([len(f) for f in stk])+len(stk)-1)
                # print(tCnt, l, stk)
                tCnt = 0
                idx = i+1
            elif ch == '\t':
                tCnt += 1
        return ret



if __name__ == '__main__':
    sol = Solution()
    print(sol.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"))
    print(sol.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"))
    print(sol.lengthLongestPath("a"))
    print(sol.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt"))
    print(sol.lengthLongestPath("a\n\tb\n\t\tc"))
    print(sol.lengthLongestPath("dir\n        file.txt"))
