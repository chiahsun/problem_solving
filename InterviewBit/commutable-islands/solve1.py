import queue

class UF:
    def __init__(self, N):
        self.id = [i for i in range(N)]
        self.sz = [1] * N
        
    def find_root(self, a):
        while self.id[a] != a:
            self.id[a] = self.id[self.id[a]]
            a = self.id[a]
        return a
        
    def is_same_union(self, a, b):
        return a == b or self.find_root(a) == self.find_root(b)
        
    def make_union(self, a, b):
        if self.is_same_union(a, b):
            return
        ra, rb = self.find_root(a), self.find_root(b)
        if self.sz[ra] < self.sz[rb]:
            ra, rb = rb, ra
        self.sz[ra] += self.sz[rb]
        self.id[rb] = self.id[ra]

class Solution:
	# @param A : integer
	# @param B : list of list of integers
	# @return an integer
	def solve(self, A, B):
        q = queue.PriorityQueue()
        for e in B:
            a, b, w = e[0]-1, e[1]-1, e[2]
            q.put((w, (a, b)))
            
        uf, res, ne = UF(A), 0, 0
        while not q.empty() and ne < A-1:
            top = q.get()
            w, a, b = top[0], top[1][0], top[1][1]
            if not uf.is_same_union(a, b):
                res += w
                ne += 1
                uf.make_union(a, b)
        return res

