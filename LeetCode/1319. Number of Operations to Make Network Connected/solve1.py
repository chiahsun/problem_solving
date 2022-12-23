class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        N = len(connections)
        if N < n-1:
            return -1
        adjs = [[] for _ in range(n)]
        for conn in connections:
            adjs[conn[0]].append(conn[1])
            adjs[conn[1]].append(conn[0])

        visited = [False] * n
        def dfs(pos):
            visited[pos] = True
            for nxt in adjs[pos]:
                if not visited[nxt]:
                    dfs(nxt)
        
        ncc = 0
        for i in range(n):
            if not visited[i]:
                ncc += 1
                dfs(i)
        return ncc-1

