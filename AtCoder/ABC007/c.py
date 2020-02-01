#!/usr/bin/env python3
import queue

r, c = [int(x) for x in input().split()]

sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
graph = []

for _ in range(r):
    graph.append(list(input()))


ans = 0
q = queue.Queue()
q.put((sy-1, sx-1, ans))
visited = [[False] * c for _ in range(r)]


while not q.empty():
    y, x, ans = q.get()

    if y == gy-1 and x == gx-1:
        print(ans)
        exit(0)
    
    if visited[y][x]:
        continue
    
    ans += 1
    visited[y][x] = True


    if not y+1 >= r and not graph[y+1][x] == '#':
        q.put((y+1, x, ans))

    if not y-1 < 0 and not graph[y-1][x] == '#':
        q.put((y-1, x, ans))

    if not x+1 >= c and not graph[y][x+1] == '#':
        q.put((y, x+1, ans))

    if not x-1 < 0 and not graph[y][x-1] == '#':
        q.put((y, x-1, ans))

