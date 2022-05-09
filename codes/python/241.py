from typing import List


class Solution:

    def calc(self, l: int, r: int) -> List[int]:
        ret_list = []
        flag = False
        for i in range(l, r+1):
            if self.expression[i] in self.op:
                flag = True
                ll = self.calc(l, i-1)
                # print(ll)
                rl = self.calc(i+1, r)
                # print(rl)
                for lv in ll:
                    for rv in rl:
                        if self.expression[i] == '+':
                            ret_list.append(lv+rv)
                        elif self.expression[i] == '-':
                            ret_list.append(lv-rv)
                        else:
                            ret_list.append(lv*rv)
        if not flag:
            # print(self.expression[l: r+1])
            ret_list = [int(self.expression[l: r+1])]
        return ret_list

    def diffWaysToCompute(self, expression: str) -> List[int]:
        self.op = ['*', '+', '-']
        self.expression = expression
        self.l = len(expression)
        return self.calc(0, self.l-1)


if __name__ == '__main__':
    sol = Solution()
    print(sol.diffWaysToCompute("2-1-1"))
    print(sol.diffWaysToCompute("2*3-4*5"))
