class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        M, N, q = len(grid), len(grid[0]), []
        
        def dfs(x, y):
            grid[x][y] = -1
            q.append((x, y))
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid[nx][ny] == 1:
                    dfs(nx, ny)

        def traversal_on_first_island():
            for i in range(M):
                for k in range(N):
                    if grid[i][k] == 1:
                        dfs(i, k)
                        return
        traversal_on_first_island()

        d = 0
        while q:
            qn = []
            for (x, y) in q:
                for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                    nx, ny = x+dx, y+dy
                    if nx >= 0 and nx < M and ny >= 0 and ny < N:
                        if grid[nx][ny] == 1:
                            return d
                        elif grid[nx][ny] == 0:
                            grid[nx][ny] = -1
                            qn.append((nx, ny))
            q = qn
            d += 1
        return -1

