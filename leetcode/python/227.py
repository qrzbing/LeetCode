from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Solution:
    def calculate(self, s: str) -> int:
        n = len(s)
        stack = []
        preSign = '+'
        num = 0
        for i in range(n):
            if s[i] != ' ' and s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
            if i == n - 1 or s[i] in '+-*/':
                if preSign == '+':
                    stack.append(num)
                elif preSign == '-':
                    stack.append(-num)
                elif preSign == '*':
                    stack.append(stack.pop() * num)
                else:
                    stack.append(int(stack.pop() / num))
                preSign = s[i]
                num = 0
        return sum(stack)


if __name__ == '__main__':
    sol = Solution()
    # print(sol.calculate("1+2"))
    # print(sol.calculate("5-2*3+1"))
    # print(sol.calculate(" 3/2 "))
    # print(sol.calculate("1+1+1"))
    # print(sol.calculate("1-1+1"))
    # print(sol.calculate("14/3*2"))
    print(sol.calculate("3+2*2"))
