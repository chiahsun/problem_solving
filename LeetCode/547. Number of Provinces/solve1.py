class UF:
    def __init__(self, N):
        self.id = list(range(N))
        self.sz = [1] * N
        self.cnt = N
    
    def is_connect(self, a, b):
        return self.find_root(a) == self.find_root(b)

    def find_root(self, a):
        while self.id[a] != a:
            self.id[a] = self.id[self.id[a]]
            a = self.id[a]
        return a
    
    def connect(self, a, b):
        if a == b:
            return

        ra, rb = self.find_root(a), self.find_root(b)
        if ra == rb:
            return

        if self.sz[b] > self.sz[a]:
            a, b = b, a

        self.sz[a] += self.sz[b]
        self.id[rb] = ra
        self.cnt -= 1

    def ncc(self):
        return self.cnt


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        uf = UF(N = N)
        for i in range(N-1):
            for k in range(i+1, N):
                if isConnected[i][k]:
                    uf.connect(i, k)
        return uf.ncc()

