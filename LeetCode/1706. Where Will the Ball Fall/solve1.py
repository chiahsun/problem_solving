class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        N = len(grid[0])
        q, row, d = list(range(N)), 0, { i: i for i in range(N)}
        while row < len(grid) and q:
            qn, dn = [], {}
            for a in q:
                if a < N and grid[row][a] == 1:
                    if a+1 < N and grid[row][a+1] == 1:
                        qn.append(a+1)
                        dn[a+1] = d[a]
                else:
                    if a-1 >= 0 and grid[row][a-1] == -1:
                        qn.append(a-1)
                        dn[a-1] = d[a]
            d = dn
            row += 1
            q = qn
        res = [-1] * N
        for a, i in d.items():
            res[i] = a
        return res
