#!/usr/bin/env python3

h, w = [int(x) for x in input().split()]
c = []

for _ in range(h):
    c.append(list(input()))

s = []
visited = [[False] * w for _ in range(h)]


def find_start():
    for j in range(h):
        for i in range(w):
            if c[j][i] == 's':
                return (j, i)


start_y, start_x = find_start()
s.append((start_y, start_x))

while len(s):
    y, x = s.pop(0)

    if c[y][x] == 'g':
        print("Yes")
        exit(0)
    
    if (not visited[y][x]) and (c[y][x] == '.' or c[y][x] == 's') :
        visited[y][x] = True

        if not y-1 < 0:
            s.append((y-1, x))

        if not y+1 >= h:
            s.append((y+1, x))

        if not x-1 < 0:
            s.append((y, x-1))

        if not x+1 >= w:
            s.append((y, x+1))

print("No")
