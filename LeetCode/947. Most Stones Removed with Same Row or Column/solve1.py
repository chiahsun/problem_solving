class UF:
    def __init__(self, N):
        self.sz = [1] * N
        self.id = list(range(N))
        self.cnt = N
    
    def is_connected(self, a, b):
        return self.find_root(a) == self.find_root(b)

    def find_root(self, a):
        while self.id[a] != a:
            self.id[a] = self.id[self.id[a]]
            a = self.id[a]
        return a

    def connect(self, a, b):
        if a == b:
            return
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        ra, rb = self.find_root(a), self.find_root(b)
        if ra == rb:
            return
        self.sz[ra] += self.sz[rb]
        self.id[rb] = ra
        self.cnt -= 1

    def ncc(self):
        return self.cnt

    
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        M, N = 0, 0
        for stone in stones:
            M, N = max(M, stone[0]+1), max(N, stone[1]+1)
        MS, NS = [None] * M, [None] * N
        for i, stone in enumerate(stones):
            if MS[stone[0]] == None:
                MS[stone[0]] = i
            if NS[stone[1]] == None:
                NS[stone[1]] = i
        uf = UF(N=len(stones))
        for i, stone in enumerate(stones):
            uf.connect(MS[stone[0]], i)
            uf.connect(NS[stone[1]], i)
        return len(stones) - uf.ncc()
        
