from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def build_hash(sStr):
            hash_set = [0] * 26
            for ch in sStr:
                hash_set[ord(ch)-ord('a')] += 1
            return tuple(hash_set)
        ret_dict = {}
        for s in strs:
            s_hash = build_hash(s)
            if s_hash not in ret_dict:
                ret_dict[s_hash] = [s]
            else:
                ret_dict[s_hash].append(s)
        return list(ret_dict.values())


if __name__ == '__main__':
    sol = Solution()
    print(sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
    print(sol.groupAnagrams([""]))
    print(sol.groupAnagrams(["a"]))
