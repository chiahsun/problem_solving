class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        N, begin = len(graph), 0
        color = [-1] * N
        q, color[begin] = [begin], 0
        while q:
            sz = len(q)
            for a in q:
                col = color[a]
                for b in graph[a]:
                    if color[b] == -1:
                        color[b] = 1-col
                        q.append(b)
                    elif color[b] == col:
                        return False
            q = q[sz:]
            while not q and begin < N:
                if color[begin] == -1:
                    color[begin] = 0
                    q.append(begin)
                    break
                begin += 1
                
        return True
