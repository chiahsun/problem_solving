class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q, n_fresh = [], 0
        for i in range(len(grid)):
            for k in range(len(grid[0])):
                if grid[i][k] == 2:
                    q.append((i, k))
                elif grid[i][k] == 1:
                    n_fresh += 1
        cnt = 0
        while q and n_fresh > 0:
            qn = []
            for (x, y) in q:
                for dx, dy in zip([0, 0, 1, -1], [1, -1, 0, 0]):
                    nx, ny = x+dx, y+dy
                    if nx >= 0 and nx < len(grid) and ny >= 0 and ny < len(grid[0]) and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        n_fresh -= 1
                        qn.append((nx, ny))
            q = qn
            if q:
                cnt += 1
        return -1 if n_fresh > 0 else cnt
