#!/usr/bin/env python3

def criticalConnections(n, edges):
    graph = [[] for _ in range(n)]
    pre = [0] * n
    low = [0] * n
    ans = []

    for u, v in edges:
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)


    def dfs(v, u, clock):
        pre[v] = clock
        low[v] = clock
        clock += 1
        
        for pair in graph[v]:
            if pre[pair] == 0:
                clock = dfs(pair, v, clock)

                low[v] = min(low[v], low[pair])

                if pre[v] < low[pair]:
                    ans.append((v+1, pair+1))
               
                
            elif not pair == u:
                low[v] = min(low[v], low[pair])


        return clock


    dfs(0, -1, 0)


    return ans




if __name__ == '__main__':
    result = criticalConnections(5, [[1, 2], [1, 3], [3, 4], [1, 4], [4, 5]])
    for bridge in result:
        print(bridge)
    print("---------------------")

    result = criticalConnections(6, [[1, 2], [1, 3], [2, 3], [2, 4], [2, 5], [4, 6], [5, 6]])
    for bridge in result:
        print(bridge)
    print("---------------------")

    result = criticalConnections(9, [[1, 2], [1, 3], [2, 3], [3, 4], [3, 6], [4, 5], [6, 7], [6, 9], [7, 8], [8, 9]])
    for bridge in result:
        print(bridge)
    print("---------------------")

    result = criticalConnections(4, [[1,2], [2,3], [2,4]])
    for bridge in result:
        print(bridge)
    print("---------------------")

    result = criticalConnections(5, [[1,2], [2,3], [2,4], [2,5] ,[4,5]])
    for bridge in result:
        print(bridge)
    print("---------------------")


