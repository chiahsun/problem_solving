class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        q, d, M, N = [], 0, len(grid), len(grid[0])

        def enqueue_neighbors(grid, q, x, y):
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and grid[nx][ny] == 0:
                    grid[nx][ny] = 2
                    q.append([nx, ny])

        for i in range(M):
            for k in range(N):
                if grid[i][k] == 1:
                    enqueue_neighbors(grid, q, i, k)

        while q:
            d += 1
            nq = []
            for e in q:
                enqueue_neighbors(grid, nq, e[0], e[1])
            q = nq
        return d if d > 0 else -1

