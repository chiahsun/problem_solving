class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        N = len(graph)
        froms = [[] for _ in range(N)]
        sz = [len(graph[i]) for i in range(N)]
        q, res = [], []
        for i, adjs in enumerate(graph):
            for to in adjs:
                froms[to].append(i)
            if not adjs:
                q.append(i)
        
        while q:
            qn = []
            for w in q:
                for v in froms[w]:
                    sz[v] -= 1
                    if sz[v] == 0:
                        qn.append(v)
            res.extend(q)
            q = qn

        return sorted(res)
