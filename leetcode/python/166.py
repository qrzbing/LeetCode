from typing import List
from collections import defaultdict


class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        d = 0
        m = 0
        if numerator == 0:
            return "0"
        tStr = ""
        flag = "-"
        if (numerator > 0 and denominator > 0) or (numerator < 0 and denominator < 0):
            flag = ""
        numerator = abs(numerator)
        denominator = abs(denominator)
        if numerator > denominator:
            d = numerator // denominator
            m = numerator % denominator
            if m == 0:
                return flag + "{}".format(d)
            else:
                tStr = flag + "{}.".format(d)
            numerator = m
        else:
            tStr = flag + "0."
        # nDict = {(numerator): len(tStr)}
        nDict = {(0, numerator): len(tStr)}
        while True:
            # for _ in range(5):
            numerator *= 10
            d = numerator // denominator
            m = numerator % denominator
            if m == 0:
                tStr += "{}".format(d)
                break
            if ((d, m) not in nDict):
                nDict[(d, m)] = len(tStr)
                tStr += "{}".format(d)
            else:
                loop = tStr[nDict[(d, m)]:]
                tStr = "{}({})".format(tStr[:nDict[(d, m)]], loop)
                break
            # print(d, m, nDict, tStr)
            numerator = m
        return tStr


if __name__ == '__main__':
    sol = Solution()
    print(sol.fractionToDecimal(4, 333), "0.(012)")
    print(sol.fractionToDecimal(1, 2), "0.5")
    print(sol.fractionToDecimal(1, 8), "0.125")
    print(sol.fractionToDecimal(2, 1), "2")
    print(sol.fractionToDecimal(1, 7), "0.(142857)")
    print(sol.fractionToDecimal(100, 7), "14.(285714)")
    print(sol.fractionToDecimal(100, 5), "20")
    print(sol.fractionToDecimal(1, 6), "0.1(6)")
    print(sol.fractionToDecimal(10, 6), "1.(6)")
    print(sol.fractionToDecimal(0, 6), "0")
    print(sol.fractionToDecimal(4, -333), "-0.(012)")
    print(sol.fractionToDecimal(-1, 2), "-0.5")
    print(sol.fractionToDecimal(1, -8), "-0.125")
    print(sol.fractionToDecimal(-2, 1), "-2")
    print(sol.fractionToDecimal(1, -7), "-0.(142857)")
    print(sol.fractionToDecimal(-100, 7), "-14.(285714)")
    print(sol.fractionToDecimal(100, -5), "-20")
    print(sol.fractionToDecimal(-1, -6), "0.1(6)")
    print(sol.fractionToDecimal(-10, -6), "1.(6)")
    print(sol.fractionToDecimal(1, 90), "0.0(1)")
    print(sol.fractionToDecimal(1, 333), "0.(003)")


"""
4/333 = 0.01* (400/333) =
              (1 + 67/333) =
                   0.1*(670/333) =
                       (2+ 4/333)

100/7 = 14* (2+2/7)
               0.1*(20/7)
                   (2+6/7)
                      0.1*(60/7)
                          (8+4/7)
                             

1/6 = 0.1 * (10 / 6)
            (1 + 4/6)
                 0.1 * (40/6)
                       6 + 4/6

1/90 = 0.01 * (100/90)
              (1 + 10/90)

1/333 = 0.1 * (10/333)
               0.1 * (100/333)
                      0.1 * (1000/333)
                             3 + 1/333
"""
