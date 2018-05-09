class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        
        NROW, NCOL = len(matrix), len(matrix[0]) if matrix else 0
        adjs = [[list() for _ in range(NCOL)] for _ in range(NROW)]
        print('adjs:', adjs)
        
        for row in range(NROW):
            for col in range(NCOL):
                cur_val = matrix[row][col]
                for dx, dy in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                    x, y = row + dx, col + dy
                    if 0 <= x < NROW and 0 <= y < NCOL and matrix[x][y] < cur_val:
                        adjs[row][col].append((x, y))
            
        # visited = [[False] * NCOL for _ in range(NROW)]
        depth = [[0] * NCOL for _ in range(NROW)]
        def dfs(row, col):
            print('dfs:', row, col)
            if depth[row][col]:
                return depth[row][col]
            
            depth[row][col] = 1
            for x, y in adjs[row][col]:
                print('  > check', x, y)
                depth[row][col] = max(depth[row][col], dfs(x, y)+1)
                
            return depth[row][col]
   
        max_depth = max_x = max_y = 0
        for i in range(NROW):
            for k in range(NCOL):
                cur_depth = dfs(i, k)
                if cur_depth > max_depth:
                    max_depth = cur_depth
                    max_x = i
                    max_y = k
        print(matrix, ' with depth:', depth)
        print('Calculate path')                
        cur_x, cur_y, cur_depth = max_x, max_y, max_depth
        path = []
        found = True 
        while found:
            print('Path x', x, 'y', y)
            cur_val = matrix[cur_x][cur_y]
            path.append(cur_val)
            
            found = False
            for dx, dy in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                x, y = cur_x + dx, cur_y + dy
                if 0 <= x < NROW and 0 <= y < NCOL and matrix[x][y] < cur_val and depth[x][y] == cur_depth-1:
                    cur_x, cur_y, cur_depth = x, y, depth[x][y]
                    found = True
                    break

        return list(reversed(path))

s = Solution()
print(s.longestIncreasingPath([[9,9,4],[6,6,8],[2,1,1]]))
print(s.longestIncreasingPath([[3,4,5],[3,2,6],[2,2,1]]))
