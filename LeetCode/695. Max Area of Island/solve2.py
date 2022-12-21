class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N, M = len(grid), len(grid[0]) if len(grid) > 0 else 0
        # Caller should ensure that this grid is 1
        def dfs(vx, vy):
            grid[vx][vy] = 0
            count = 0
            for dx, dy in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                x, y = vx+dx, vy+dy
                if x >= 0 and x < N and y >= 0 and y < M and grid[x][y] != 0:
                    count += dfs(x, y)
            return 1 + count
                    
        max_count = 0
        for i in range(N):
            for k in range(M):
                if grid[i][k]:
                    max_count = max(max_count, dfs(i, k))
        return max_count

