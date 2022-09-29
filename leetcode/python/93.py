from typing import List
from collections import defaultdict


class Solution:

    def restoreIpAddresses(self, s: str) -> List[str]:
        def validAddr(addr):
            # print(addr)
            if len(addr) > 1 and addr[0] == "0":
                return False
            ip_n = int(addr, 10)
            if ip_n > 255:
                return False
            return True
        ret = []
        lIP = len(s)
        # print(lIP)
        for i in range(1, lIP-2):
            for j in range(i+1, lIP-1):
                for k in range(j+1, lIP):
                    if validAddr(s[0:i]) and validAddr(s[i:j]) and validAddr(s[j:k]) and validAddr(s[k:lIP]):
                        ret.append("{}.{}.{}.{}".format(
                            s[0:i], s[i:j], s[j:k], s[k:lIP]))
        return ret


if __name__ == '__main__':
    sol = Solution()
    print(sol.restoreIpAddresses("0000"))
    print(sol.restoreIpAddresses("101023"))
    print(sol.restoreIpAddresses("25525511135"))
