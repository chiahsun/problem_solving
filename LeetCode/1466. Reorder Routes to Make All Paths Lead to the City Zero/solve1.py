class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        T, F = [[] for _ in range(n)], [[] for _ in range(n)]
        for conn in connections:
            f, t = conn[0], conn[1]
            T[f].append(t)
            F[t].append(f)

        res = 0
        def dfs(pos):
            nonlocal res
            for f in F[pos]:
                T[f].remove(pos)
                dfs(f)
            for t in T[pos]:
                F[t].remove(pos)
                res += 1
                dfs(t)
        dfs(0)

        return res
