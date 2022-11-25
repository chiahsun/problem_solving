class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        N = len(grid[0])
        q, res, row = list(range(N)), list(range(N)), 0
        while row < len(grid) and q:
            qn = []
            for i in q:
                a = res[i]
                if a < N and grid[row][a] == 1:
                    if a+1 < N and grid[row][a+1] == 1:
                        qn.append(i)
                        res[i] = a+1
                    else:
                        res[i] = -1
                else:
                    if a-1 >= 0 and grid[row][a-1] == -1:
                        qn.append(i)
                        res[i] = a-1
                    else:
                        res[i] = -1
            row += 1
            q = qn
        return res
