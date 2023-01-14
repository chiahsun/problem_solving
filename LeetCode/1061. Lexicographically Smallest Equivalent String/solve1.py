class UnionFind:
    def __init__(self, N):
        self.parent = [i for i in range(N)]
        self.id = [i for i in range(N)]
        self.cnt = [1] * N

    def make_union(self, a, b):
        ra, rb = self.find_root(a), self.find_root(b)
        if ra == rb:
            return
        if self.cnt[ra] < self.cnt[rb]:
            ra, rb = rb, ra
        self.cnt[ra] += self.cnt[rb]
        self.parent[rb] = ra
        self.id[ra] = self.id[rb] = min(self.id[ra], self.id[rb])

    def find_root(self, a):
        while self.parent[a] != a:
            self.parent[a] = self.parent[self.parent[a]]
            a = self.parent[a]
        return a

    def get_id(self, a):
        return self.id[self.find_root(a)]


class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        def get_ord(c):
            return ord(c) - ord('a')
        def get_char(n):
            return chr(ord('a') + n)

        uf = UnionFind(26)
        for i in range(len(s1)):
            a, b = get_ord(s1[i]), get_ord(s2[i])
            uf.make_union(a, b)
        return "".join([get_char(uf.get_id(get_ord(c))) for c in baseStr])

