import queue


class Solution:
	# @param A : integer
	# @param B : list of list of integers
	# @return an integer
	def solve(self, A, B):
        q, ADJ = queue.PriorityQueue(), [[] for _ in range(A)]
        for i, e in enumerate(B):
            a, b, w = e[0]-1, e[1]-1, e[2]
            B[i] = [a, b, w]
            ADJ[a].append(i)
            ADJ[b].append(i)
            if a == 0 or b == 0:
                q.put((w, i))

        intree, res, ne = [False] * A, 0, 0
        intree[0] = True
        while not q.empty() and ne < A-1:
            top = q.get()
            w, eid = top[0], top[1]
            a, b = B[eid][0], B[eid][1]
            target = -1
            if not intree[a]:
                target = a
            elif not intree[b]:
                target = b
            if target != -1:
                intree[target] = True
                res += w
                ne += 1
                for nxt_eid in ADJ[target]:
                    if not intree[B[nxt_eid][0]] or not intree[B[nxt_eid][1]]:
                        q.put((B[nxt_eid][2], nxt_eid))
        return res

