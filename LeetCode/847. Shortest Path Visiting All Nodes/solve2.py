import queue

class State:
    # Note that n <= 12 so we don't need to care about overflow
    def __init__(self, N):
        self.A = 1 << N

    def is_set(self, pos):
        return self.A & (0x1 << pos)

    def set(self, pos):
        self.A |= (0x1 << pos)

    def unset(self, pos):
        self.A &= ~(0x1 << pos)

    def count(self):
        a, cnt = self.A, -1
        while a > 0:
            a &= (a-1)
            cnt += 1
        return cnt

    def __repr__(self):
        return bin(self.A)

    def __hash__(self):
        return self.A

    def __eq__(self, other):
        return other.A == self.A

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        N = len(graph)

        def node_order(N, graph):
            res, q = [], queue.PriorityQueue()
            E = copy.deepcopy(graph) # E = graph[:] only shallow copy
            for i, nxts in enumerate(E):
                q.put((len(nxts), i))
            while not q.empty():
                to_remove = []
                top_priority = q.queue[0][0]
                while not q.empty() and q.queue[0][0] <= top_priority:
                    priority, i = q.get()
                    if i not in res:
                        to_remove.append(i)
                        res.append(i)
                to_do = set()
                for i in to_remove:
                    for to in E[i]:
                        E[to].remove(i)
                        to_do.add(to)
                for i in to_do:
                    if i not in res:
                        q.put((len(E[i]), i))
            order = [0] * N
            for i, v in enumerate(res):
                order[v] = i
            return order

        def backtracking(A, S, SS, best):
            cur_state = (S, A[-1])
            if cur_state in SS and len(A) >= SS[cur_state]:
                return

            if len(A) >= best[0]:
                return
            visited_size = S.count()
            if N-visited_size >= best[0]-len(A):
                return
            if visited_size == N:
                cur = len(A)
                if cur < best[0]:
                    best[0] = cur
                return

            SS[cur_state] = len(A)
            postponed, nxts = [], []
            for nxt in graph[A[-1]]:
                if len(graph[A[-1]]) > 1 and ((len(A) > 1 and nxt == A[-2]) or nxt in A):
                    postponed.append(nxt)
                else:
                    nxts.append(nxt)

            nxts.extend(postponed)
            for i, nxt in enumerate(nxts):
                is_new = not S.is_set(nxt)
                if N-visited_size-1 >= best[0]-len(A)-1:
                    break
                if N-visited_size-(1 if is_new else 0) >= best[0]-len(A)-1:
                    continue
                if is_new:
                    S.set(nxt)
                A.append(nxt)
                backtracking(A, S, SS, best)
                A.pop()
                if is_new:
                    S.unset(nxt)

        order = node_order(N, graph)
        best, nodes = [2*N], sorted(list(range(N)), key=lambda x: order[x])

        for i, tos in enumerate(graph):
            graph[i] = sorted(tos, key=lambda x: order[x])
        for i in nodes:
            S = State(N)
            S.set(i)
            backtracking([i], S, dict(), best)

        return best[0]-1
