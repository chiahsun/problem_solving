class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        def dfs(grid, x, y):
            cnt = 1
            grid[x][y] = 0
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid[nx][ny] == 1:
                    cnt += dfs(grid, nx, ny)
            return cnt
        res = 0
        for i in range(M):
            for k in range(N):
                if grid[i][k] == 1:
                    res = max(res, dfs(grid, i, k))
        return res
