class UnionFind:
    
    def __init__(self, N, vals):
        self.parent = [i for i in range(N)]
        self.cnt = [1] * N
        self.vals = [defaultdict(int) for _ in range(N)]
        for i, val in enumerate(vals):
            self.vals[i][val] = 1

    def find_root(self, a):
        while self.parent[a] != a:
            self.parent[a] = self.parent[self.parent[a]]
            a = self.parent[a]
        return a

    def is_same_union(self, a, b):
        return self.find_root(a) == self.find_root(b)

    def make_union(self, a, b):
        ra, rb = self.find_root(a), self.find_root(b)
        if ra == rb:
            return
        if self.cnt[ra] < self.cnt[rb]:
            ra, rb = rb, ra
        self.cnt[ra] += self.cnt[rb]
        self.parent[rb] = ra
        for val in self.vals[rb]:
            self.vals[ra][val] +=  self.vals[rb][val]

    def count(self, a, val):
        return self.vals[self.find_root(a)][val]



class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        N = len(vals)
        E = [[] for _ in range(N)]
        for e in edges:
            a, b = e[0], e[1]
            E[a].append(b)
            E[b].append(a)

        order = list(range(N))
        order.sort(key=lambda i: vals[i])
        
        uf = UnionFind(N, vals)
        old_val, res = -1, 0
        for i in range(N+1):
            if i == N or vals[order[i]] != old_val:
                if i < N:
                    old_val = vals[order[i]]
                tocal_val = vals[order[i-1]]
                ids = set()
                for k in range(i-1, -1, -1):
                    if vals[order[k]] != tocal_val:
                        break
                    ids.add(uf.find_root(order[k]))
                for id in ids:
                    cnt = uf.count(id, tocal_val)
                    res += (cnt+1)*cnt//2 
                
            if i == N:
                break
            cur = order[i]
            cur_val = vals[cur]
            for nxt in E[cur]:
                nxt_val = vals[nxt]
                if nxt_val <= cur_val:
                    uf.make_union(cur, nxt)

        return res

