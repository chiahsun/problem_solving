import queue
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        N = len(grid)
        if grid[0][0] == 1 or grid[N-1][N-1] == 1:
            return -1
        q = queue.PriorityQueue()
        q.put((N, (1, 0, 0)))
        grid[0][0] = N
        while not q.empty():
            e = q.get()
            cost, x, y = e[1][0], e[1][1], e[1][2]
            if x == N-1 and y == N-1:
                return cost
            for dx, dy in [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]:
                nx, ny = x + dx, y + dy
                nx_cost = cost+1
                min_expected_cost = nx_cost + max(N-1-nx, N-1-ny)
                if nx >= 0 and nx < N and ny >= 0 and ny < N and (grid[nx][ny] == 0 or min_expected_cost < grid[nx][ny]):
                    grid[nx][ny] = min_expected_cost
                    q.put((min_expected_cost, (nx_cost, nx, ny)))
        return -1
