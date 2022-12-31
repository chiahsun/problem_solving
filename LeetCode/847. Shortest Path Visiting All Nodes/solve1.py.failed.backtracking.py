class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        N = len(graph)
        def backtracking(A, S, best):
            if len(A) >= best[0]:
                # print('Stop at: ', A)
                return
            sz = len(S)
            if N-sz >= best[0]-len(A):
                # print('Stop 2 at: ', A)
                return
            if sz == N:
                # print(A, sz)
                cur = len(A)
                if cur < best[0]:
                    best[0] = cur
                    # print('Update bests to ', best, ' > ', A)
                return
     
            postponed = [] 
            for nxt in graph[A[-1]]:
                if len(graph[A[-1]]) > 1 and ((len(A) > 1 and nxt == A[-2]) or nxt in A):
                    postponed.append(nxt)
                    continue
                is_new = False
                if nxt not in S:
                    is_new = True
                S.add(nxt)
                A.append(nxt)
                backtracking(A, S, best)
                A.pop()
                if is_new:
                    S.remove(nxt)
            for nxt in postponed:
                A.append(nxt)
                backtracking(A, S, best)
                A.pop()

        best = [2*N]
        for i in range(N):
            backtracking([i], {i}, best)

        return best[0]-1
