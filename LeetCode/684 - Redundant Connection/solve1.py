class Solution:
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        N = len(edges)+1
        degrees = [0] * N
        adjs = [set() for _ in range(N)]
        has_edge = [True] * N
        has_edge[0] = False
        for edge in edges:
            a, b = edge[0], edge[1]
            adjs[a].add(b)
            adjs[b].add(a)
            degrees[a] += 1
            degrees[b] += 1
        todo = []
        for i in range(0, N): 
            adj = adjs[i]
            if len(adj) == 1:
                for e in adj: # Retreieve the only element
                    todo.append([i, e])
                    break

        while todo:
            last = todo.pop()
            a, b = last[0], last[1]
            has_edge[a] = False
            adjs[a].remove(b)
            adjs[b].remove(a)
            if len(adjs[b]) == 1:
                for e in adjs[b]: # Retreieve the only element
                    todo.append([b, e])
                    break
        for edge in reversed(edges):
            if has_edge[edge[0]] and has_edge[edge[1]]:
                return edge
        return None 
    

