class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        
        NROW, NCOL = len(matrix), len(matrix[0]) if matrix else 0
        adjs = [[list() for _ in range(NCOL)] for _ in range(NROW)]
        
        for row in range(NROW):
            for col in range(NCOL):
                cur_val = matrix[row][col]
                for dx, dy in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                    x, y = row + dx, col + dy
                    if 0 <= x < NROW and 0 <= y < NCOL and matrix[x][y] < cur_val:
                        adjs[row][col].append((x, y))
            
        max_depth = 0
        depth = [[0] * NCOL for _ in range(NROW)]
        def dfs(row, col):
            nonlocal max_depth
            if depth[row][col]:
                return depth[row][col]
            
            depth[row][col] = 1
            for x, y in adjs[row][col]:
                depth[row][col] = max(depth[row][col], dfs(x, y)+1)
            max_depth = max(max_depth, depth[row][col])
            return depth[row][col]
        for i in range(NROW):
            for k in range(NCOL):
                dfs(i, k)
        return max_depth

