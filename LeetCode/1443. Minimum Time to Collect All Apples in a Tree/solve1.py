class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        E = [[] for _ in range(n)]
        for e in edges:
            a, b = e[0], e[1]
            E[a].append(b)
            E[b].append(a)
        
        def traversal(pos, parent=None):
            res = 0
            for nxt in E[pos]:
                if nxt != parent:
                    res += traversal(nxt, pos)
            if pos != 0 and (res > 0 or hasApple[pos]):
                res += 1

            return res

        return 2 * traversal(0)
