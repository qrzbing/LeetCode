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
        def dfs(idx, node) -> bool:
            # print("dfs ", idx)
            if idx >= len(word):
                return node.isEnd
            ch = word[idx]
            if ch != ".":
                child = node.child[ord(ch)-ord('a')]
                if child is not None and dfs(idx+1, child):
                    return True
            else:
                for child in node.child:
                    if child is not None and dfs(idx+1, child):
                        return True
            return False
        return dfs(0, self)


class WordDictionary:

    def __init__(self):
        self.dic = Trie()

    def addWord(self, word: str) -> None:
        self.dic.insert(word)

    def search(self, word: str) -> bool:
        return self.dic.search(word)

        # Your WordDictionary object will be instantiated and called as such:
        # obj = WordDictionary()
        # obj.addWord(word)
        # param_2 = obj.search(word)
if __name__ == '__main__':
    sol = WordDictionary()
    sol.addWord("at")
    sol.addWord("and")
    sol.addWord("an")
    sol.addWord("add")
    print(sol.search("a"))
    print(sol.search(".at"))
    sol.addWord("bat")
    print(sol.search(".at"))
    print(sol.search("an."))
    print(sol.search("a.d."))
    print(sol.search("b."))
    print(sol.search("a.d"))
    print(sol.search("."))
