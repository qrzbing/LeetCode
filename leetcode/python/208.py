from typing import List
from collections import defaultdict
from functools import cmp_to_key


class Trie:

    def __init__(self):
        self.isEnd = False
        self.child = [None] * 26

    def insert(self, word: str) -> None:
        node = self
        for ch in word:
            ch = ord(ch)-ord('a')
            if not node.child[ch]:
                node.child[ch] = Trie()
            node = node.child[ch]
        node.isEnd = True

    def search(self, word: str) -> bool:
        node = self
        for ch in word:
            ch = ord(ch)-ord('a')
            if not node.child[ch]:
                return False
            else:
                node = node.child[ch]
        return node.isEnd

    def startsWith(self, prefix: str) -> bool:
        node = self
        for ch in prefix:
            ch = ord(ch)-ord('a')
            if not node.child[ch]:
                return False
            else:
                node = node.child[ch]
        return True

        # Your Trie object will be instantiated and called as such:
        # obj = Trie()
        # obj.insert(word)
        # param_2 = obj.search(word)
        # param_3 = obj.startsWith(prefix)


if __name__ == '__main__':
    sol = Solution()
