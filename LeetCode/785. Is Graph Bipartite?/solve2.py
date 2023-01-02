class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        N = len(graph)
        color = [-1] * N
        def dfs(a, col=0):
            if color[a] != -1:
                return color[a] == col
            color[a] = col
            return all(dfs(b, 1-col) for b in graph[a])
                
        return all(color[i] != -1 or dfs(i) for i in range(N))
