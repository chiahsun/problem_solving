class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        N = len(vals)
        E = [[] for _ in range(N)]
        for e in edges:
            a, b = e[0], e[1]
            E[a].append(b)
            E[b].append(a)
        res, calculated = 0, [False] * N
        def dfs(pos, val, visited):
            if vals[pos] == val:
                calculated[pos] = True
            cnt = (vals[pos] == val)
            visited[pos] = True
            for nxt in E[pos]:
                if not visited[nxt] and vals[nxt] <= val:
                    cnt += dfs(nxt, val, visited)
            return cnt
        for i in range(N):
            visited = [False] * N
            if not calculated[i]:
                cnt = dfs(i, vals[i], visited)
                res += (cnt * (cnt+1)) // 2

        return res

