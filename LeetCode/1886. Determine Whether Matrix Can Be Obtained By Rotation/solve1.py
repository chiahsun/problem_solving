class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def rotate():
            start, end = 1, len(mat)
            while start < end:
                # print('start end', start, end)
                for i in range(start, end):
                    x, y = start-1, i
                    backup = mat[x][y]
                    for k in range(4):
                        # print(x, y)
                        nx, ny = end+start-y-2, x
                        if k != 3:
                            # print('Set x y', x, y, mat[x][y], ' as nx ny', nx, ny, mat[nx][ny])
                            mat[x][y] = mat[nx][ny]
                        else:
                            # print('Set x y', x, y, mat[x][y], ' as backup', backup)
                            mat[x][y] = backup
                        x, y = nx, ny
                start += 1; end -= 1
            # print(mat) 
        for _ in range(4):
            # print(mat) 
            if mat == target:
                return True
            rotate()
        return False  

