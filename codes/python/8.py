from typing import List
from collections import defaultdict


class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        # print(s)
        sign_flag = True
        ret = 0
        for i, ch in enumerate(s):
            if ch == '-':
                if i == 0:
                    sign_flag = False
                    continue
                else:
                    break
            if ch == '+':
                if i == 0:
                    continue
                else:
                    break
            if ord(ch)>=ord('0') and ord(ch)<=ord('9'):
                ret = ret * 10 + (ord(ch)-ord('0'))
                if ret > ((1<<31)-1) and sign_flag is True:
                    ret = (1<<31)-1
                    break
                elif ret > (1<<31) and sign_flag is False:
                    ret = 1<<31
                    break
            else:
                break
        if sign_flag is False:
            ret = -ret
        return ret




if __name__ == '__main__':
    sol = Solution()
    print(sol.myAtoi("42"))
    print(sol.myAtoi("   -42"))
    print(sol.myAtoi("4193 with words"))
    print(sol.myAtoi("-91283472332"))
    print(sol.myAtoi("    91283472332"))
    # print(2<<30)
