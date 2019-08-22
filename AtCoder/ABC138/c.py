#!/usr/bin/env python3

n = int(input().rstrip())
v_lst = [int(x) for x in input().rstrip().split()]

sorted_v_lst = sorted(v_lst)
ans = (sorted_v_lst[0] + sorted_v_lst[1] ) / 2

for i in range(2, len(sorted_v_lst)):
  ans = (ans + sorted_v_lst[i]) / 2
  
print(ans)
