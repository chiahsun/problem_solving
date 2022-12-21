class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        M, N = len(grid1), len(grid1[0])

        def fill(grid, x, y, v):
            grid[x][y] = v
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx , ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid[nx][ny] == 1:
                    fill(grid, nx, ny, v)

        def dfs(grid1, grid2, x, y, v):
            same = grid1[x][y] == v
            grid2[x][y] = 0
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx , ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid2[nx][ny] == 1:
                    if not dfs(grid1, grid2, nx, ny, v):
                        same = False
            return same

        id = 2
        for i in range(M):
            for k in range(N):
                if grid1[i][k] == 1:
                    fill(grid1, i, k, id)
                    id += 1
        res = 0
        for i in range(M):
            for k in range(N):
                if grid2[i][k] == 1 and grid1[i][k] != 0:
                    if dfs(grid1, grid2, i, k, grid1[i][k]):
                        res += 1
        return res
