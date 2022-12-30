class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        reds, blues = [[] for _ in range(n)], [[] for _ in range(n)]
        for e in redEdges:
            reds[e[0]].append(e[1])
        for e in blueEdges:
            blues[e[0]].append(e[1])
        # -1: unreachable, 0: blue, 1: red, 2: both
        colors, q, d = [-1] * n, [], [-1] * n
        colors[0] = 2
        d[0] = 0
        q.append((2, 0))
        cnt = 0
        while q:
            qn = []
            cnt += 1
            for v, a in q:
                if v == 2 or v == 0:
                    for b in reds[a]:
                        if colors[b] == -1:
                            colors[b] = 1
                            qn.append((1, b))
                        elif colors[b] == 0:
                            colors[b] = 2
                            qn.append((2, b))
                        if d[b] == -1:
                            d[b] = cnt
                if v == 2 or v == 1:
                    for b in blues[a]:
                        if colors[b] == -1:
                            colors[b] = 0
                            qn.append((0, b))
                        elif colors[b] == 1:
                            colors[b] = 2
                            qn.append((2, b))
                        if d[b] == -1:
                            d[b] = cnt
            q = qn
        return d

