class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        start, end = 1, len(matrix)
        while start < end:
            for i in range(start, end):
                x, y = start-1, i
                backup = matrix[x][y]
                for k in range(4):
                    nx, ny = end+start-y-2, x
                    if k != 3:
                        matrix[x][y] = matrix[nx][ny]
                    else:
                        matrix[x][y] = backup
                    x, y = nx, ny
            start += 1; end -= 1
