class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        color, E = [-1] * n, [[] for _ in range(n)]
        for dis in dislikes:
            a, b = dis[0]-1, dis[1]-1
            E[a].append(b)
            E[b].append(a)

        def dfs(a, col=0):
            if color[a] != -1:
                return color[a] == col
        
            color[a] = col
            return all(dfs(nxt, 1-col) for nxt in E[a])

        return all(dfs(i) for i in range(n) if color[i] == -1)
        

