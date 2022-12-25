class UF:
    def __init__(self, N):
        self.N = N
        self.id = [i for i in range(N)]
        self.sz = [1] * N
        
    def make_union(self, a, b):
        if a == b:
            return
        ra, rb = self.find_root(a), self.find_root(b)
        if ra == rb:
            return
        if self.sz[ra] < self.sz[rb]:
            ra, rb = rb, ra
        self.sz[ra] += self.sz[rb]
        self.id[rb] = ra
    
    def find_root(self, a):
        while self.id[a] != a:
            self.id[a] = self.id[self.id[a]]
            a = self.id[a]
        return a
        
    def is_same_union(self, a, b):
        if a == b:
            return True
        return self.find_root(a) == self.find_root(b)
    
        
        
        
class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B):        
        uf = UF(A)
        for e in B:
            a, b = e[0]-1, e[1]-1
            if uf.is_same_union(a, b):
                return 1
            uf.make_union(a, b)
        return 0

