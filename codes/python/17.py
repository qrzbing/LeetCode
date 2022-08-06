from typing import List
from collections import defaultdict


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        table_list = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        l = len(digits)

        def backtrace(idx) -> str:
            if idx >= l:
                return []
            ret = []
            if idx == l-1:
                for ch in table_list[digits[idx]]:
                    ret.append(ch)
                return ret
            for ch in table_list[digits[idx]]:
                for s in backtrace(idx+1):
                    ret.append(ch+s)
            # print(ret)
            return ret
        
        
        return backtrace(0)

if __name__ == '__main__':
    sol = Solution()
    print(sol.letterCombinations("23"))
    print(sol.letterCombinations(""))
    print(sol.letterCombinations("2"))
    print(sol.letterCombinations("5678"))
