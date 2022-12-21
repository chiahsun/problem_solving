class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])

        def fill(grid, x, y):
            grid[x][y] = 0
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid[nx][ny] == 1:
                    fill(grid, nx, ny)
        for i in range(M):
            if grid[i][0] == 1:
                fill(grid, i, 0)
            if grid[i][N-1] == 1:
                fill(grid, i, N-1)

        for i in range(N):
            if grid[0][i] == 1:
                fill(grid, 0, i)
            if grid[M-1][i] == 1:
                fill(grid, M-1, i)

        res = 0
        for i in range(M):
            for k in range(N):
                if grid[i][k] == 1:
                    res += 1
        return res

