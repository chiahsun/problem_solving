class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])

        def fill(grid, x, y):
            grid[x][y] = 1
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid[nx][ny] == 0:
                    fill(grid, nx, ny)


        
        for i in range(M):
            if grid[i][0] == 0:
                fill(grid, i, 0)
            if grid[i][N-1] == 0:
                fill(grid, i, N-1)

        for i in range(N):
            if grid[0][i] == 0:
                fill(grid, 0, i)
            if grid[M-1][i] == 0:
                fill(grid, M-1, i)

        res = 0
        for i in range(M):
            for k in range(N):
                if grid[i][k] == 0:
                    res += 1
                    fill(grid, i, k)
        return res
