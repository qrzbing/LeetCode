from typing import List
from collections import defaultdict


class Solution:
    def intToRoman(self, num: int) -> str:
        table_list = [
            ["I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
            ["X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
            ["C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
            ["M", "MM", "MMM"]
        ]
        ret_str = ""
        i = 0
        while num > 0:
            mod_num = num % 10
            if mod_num != 0:
                ret_str = table_list[i][mod_num-1] + ret_str
            num = num // 10
            i += 1
        return ret_str

if __name__ == '__main__':
    sol = Solution()
    print(sol.intToRoman(3))
    print(sol.intToRoman(4))
    print(sol.intToRoman(9))
    print(sol.intToRoman(58))
    print(sol.intToRoman(1994))
    print(sol.intToRoman(10))
    print(sol.intToRoman(100))
    print(sol.intToRoman(1000))
