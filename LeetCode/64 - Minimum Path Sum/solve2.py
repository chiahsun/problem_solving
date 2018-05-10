class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        M, N = len(grid), len(grid[0])
        D = [[0x7FFFFFFF]*N for _ in range(M)]
        for i in range(N):
            D[0][i] = (D[0][i-1] if i > 0 else 0) + grid[0][i]
        for i in range(M):
            D[i][0] = (D[i-1][0] if i > 0 else 0) + grid[i][0]
        
        for i in range(1, M):
            for k in range(1, N):
                D[i][k] = min(D[i-1][k], D[i][k-1]) + grid[i][k]
                
        return D[M-1][N-1]
