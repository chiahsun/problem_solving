class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:

        def get_pos(c):
            return ord(c) - ord('a')
        E = [[] for _ in range(n)]
        for e in edges:
            a, b = e[0], e[1]
            E[a].append(b)
            E[b].append(a)
        M = max(map(lambda c: get_pos(c), labels))+1
        C = [[0] * M for _ in range(n)]

        def traversal(pos, parent=None):
            for nxt in E[pos]:
                if nxt != parent:
                    T = traversal(nxt, pos)
                    for k in range(M):
                        C[pos][k] += T[k]
            C[pos][get_pos(labels[pos])] += 1
            return C[pos]

        traversal(0)
        res = []
        for i in range(n):
            pos = get_pos(labels[i])
            res.append(C[i][pos])
        return res
