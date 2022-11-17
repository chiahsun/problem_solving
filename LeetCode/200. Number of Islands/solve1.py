class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        NX, NY = len(grid), len(grid[0])
        def dfs(x, y):
            grid[x][y] = 0
            for dx, dy in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < NX and ny >= 0 and ny < NY and grid[nx][ny] == '1':
                    dfs(nx, ny)
        ans = 0
        for x in range(NX):
            for y in range(NY):
                if grid[x][y] == '1':
                    ans += 1; dfs(x, y)
        return ans

