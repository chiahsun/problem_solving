class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        N = len(vals)
        E = [[] for _ in range(N)]
        for e in edges:
            a, b = e[0], e[1]
            E[a].append(b)
            E[b].append(a)
        res = 0
        def dfs(pos, val, visited):
            nonlocal res
            if vals[pos] == val:
                res += 1
            visited[pos] = True
            for nxt in E[pos]:
                if not visited[nxt] and vals[nxt] <= val:
                    dfs(nxt, val, visited)
        for i in range(N):
            visited = [False] * N
            dfs(i, vals[i], visited)

        return (res + N)// 2

