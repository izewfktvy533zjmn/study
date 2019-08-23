#!/usr/bin/env python3
from collections import deque

n, q = [int(x) for x in input().rstrip().split()]
branch_lst = [[] for _ in range(n)]
val_lst = [0 for _ in range(n)]

for _ in range(n-1):
    a, b = [int(x) for x in input().rstrip().split()]
    branch_lst[a-1].append(b-1)

for _ in range(q):
    p, x = [int(x) for x in input().rstrip().split()]
    val_lst[p-1] += x

d = deque()
d.append(0)

while len(d):
    parent = d.popleft()

    for child in branch_lst[parent]:
        d.append(child)
        val_lst[child] += val_lst[parent]


print(' '.join(map(str, val_lst)))
