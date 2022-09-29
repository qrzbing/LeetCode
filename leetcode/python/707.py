from typing import List, Optional
from collections import defaultdict, Counter, deque
from functools import cmp_to_key


class MyNode:
    def __init__(self, val: int) -> None:
        self.val = val
        self.next = None


class MyLinkedList:

    def __init__(self):
        self.head: MyNode = MyNode(0)
        self.size: int = 0

    def get(self, index: int) -> int:
        if index < 0 or self.size <= index:
            return -1
        node: MyNode = self.head
        for _ in range(index+1):
            node = node.next
        return node.val

    def addAtHead(self, val: int) -> None:
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        self.addAtIndex(self.size, val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.size:
            return
        tNode = self.head
        for _ in range(index):
            tNode = tNode.next
        nNode = MyNode(val)
        nNode.next = tNode.next
        tNode.next = nNode
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        p = self.head
        for _ in range(index):
            p = p.next
        p.next = p.next.next
        self.size -= 1


if __name__ == '__main__':
    pass
    # sol = Solution()
