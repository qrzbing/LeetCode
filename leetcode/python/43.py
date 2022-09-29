from typing import List
from collections import defaultdict


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def strip_0(num: str):
            for i, ch in enumerate(num):
                if ch != "0":
                    return num[i:]
            return "0"

        def add_str(n1: str, n2: str):
            ret_str = ""
            l1 = len(n1)
            l2 = len(n2)
            i = l1-1
            j = l2-1
            tick = 0
            while i >= 0 and j >= 0:
                cur = (ord(n1[i])-ord('0'))+(ord(n2[j])-ord('0'))+tick
                if cur >= 10:
                    tick = 1
                    cur = cur % 10
                else:
                    tick = 0
                ret_str = str(cur) + ret_str
                i -= 1
                j -= 1
            while i >= 0:
                cur = (ord(n1[i])-ord('0'))+tick
                if cur >= 10:
                    tick = 1
                    cur = cur % 10
                else:
                    tick = 0
                ret_str = str(cur) + ret_str
                i -= 1
            while j >= 0:
                cur = (ord(n2[j])-ord('0'))+tick
                if cur >= 10:
                    tick = 1
                    cur = cur % 10
                else:
                    tick = 0
                ret_str = str(cur) + ret_str
                j -= 1
            if tick == 1:
                ret_str = "1" + ret_str
            return ret_str

        def mut_str(n1: str, n2):
            ret_str = ""
            tick = 0
            mut = ord(n2) - ord('0')
            for i in range(len(n1)-1, -1, -1):
                cur = (ord(n1[i])-ord('0'))*mut+tick
                if cur >= 10:
                    tick = cur // 10
                    cur = cur % 10
                else:
                    tick = 0
                ret_str = str(cur) + ret_str

            if tick != 0:
                ret_str = str(tick) + ret_str

            return ret_str

        ret = ""
        cnt = 0
        for i in range(len(num2)-1, -1, -1):
            cur_str = strip_0(mut_str(num1, num2[i]))
            for _ in range(cnt):
                cur_str = cur_str + "0"
            ret = add_str(cur_str, ret)
            cnt += 1

        return strip_0(ret)


if __name__ == '__main__':
    sol = Solution()
    print(sol.multiply("123456789", "234567890"))
    print(sol.multiply("999999999", "1234"))
    print(sol.multiply("2", "3"))
    print(sol.multiply("123", "456"))
    print(sol.multiply("0", "456"))
