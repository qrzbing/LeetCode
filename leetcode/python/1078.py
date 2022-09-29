from typing import List


class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        ret = []
        words = text.split(" ")
        words_len = len(words)
        for i in range(0, words_len - 1):
            if words[i] == first and words[i+1] == second:
                if i+2 < words_len:
                    ret.append(words[i+2])
        return ret

sol = Solution()
print(sol.findOcurrences("alice is a good girl she is a good student", "a", "good"))
