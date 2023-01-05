from typing import List, Optional
from collections import defaultdict, Counter, deque
from functools import cmp_to_key



if __name__ == '__main__':
    m, n = map(int, input().strip().split())
    box = []
    for _ in range(m):
        box.append(list(map(int, input().strip().split())))
    print(box)
