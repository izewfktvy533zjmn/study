#!/usr/bin/env python3

#h, w = map(int, input().split())
h, w = [int(x) for x in input().split()]
c = []
visited = [[False] * w for _ in range(h)]

for _ in range(h):
    c.append(list(input()))


def find_start():
    for j in range(h):
        for i in range(w):
            if c[j][i] == 's':
                return (j, i)


def dfs(j, i):
    if c[j][i] == 'g':
        print("Yes")
        exit(0)
    
    visited[j][i] = True
    
    if 0 <= j+1 < h and (not c[j+1][i] == '#') and visited[j+1][i] == False:
        dfs(j+1, i)

    if 0 <= j-1 < h and (not c[j-1][i] == '#') and visited[j-1][i] == False:
        dfs(j-1, i)
    
    if 0 <= i+1 < w and (not c[j][i+1] == '#') and visited[j][i+1] == False:
        dfs(j, i+1)
    
    if 0 <= i-1 < w and (not c[j][i-1] == '#') and visited[j][i-1] == False:
        dfs(j, i-1)




start_x, start_y = find_start()
dfs(start_x, start_y)
print("No")

