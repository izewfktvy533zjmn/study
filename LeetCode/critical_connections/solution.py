#!/usr/bin/env python3

class Solution:
    def criticalConnections(self, n, edges):
        graph = [[] for _ in range(n)]

        for node1, node2 in edges:
            graph[node1-1].append(node2-1)
            graph[node2-1].append(node1-1)
            
        pre = [0] * n
        low = [0] * n
        time = 0

        def dfs(node, pair):
            

        return graph



if __name__ == '__main__':
    s = Solution()
    result = s.criticalConnections(5, [[1, 2], [1, 3], [3, 4], [1, 4], [4, 5]])
    print(result)

    result = s.criticalConnections(6, [[1, 2], [1, 3], [2, 3], [2, 4], [2, 5], [4, 6], [5, 6]])
    print(result)

    result = s.criticalConnections(9, [[1, 2], [1, 3], [2, 3], [3, 4], [3, 6], [4, 5], [6, 7], [6, 9], [7, 8], [8, 9]])
    print(result)

