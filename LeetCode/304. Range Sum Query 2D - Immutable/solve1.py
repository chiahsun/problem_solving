class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.psum = [[0 for _ in range(len(matrix[0])+1)] for _ in range(len(matrix)+1)]
        for i in range(1, len(matrix)+1):
            for k in range(1, len(matrix[0])+1):
                self.psum[i][k] = self.psum[i][k-1] + self.psum[i-1][k] - self.psum[i-1][k-1] + matrix[i-1][k-1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.psum[row2+1][col2+1] - self.psum[row1][col2+1] - self.psum[row2+1][col1] + self.psum[row1][col1]

    
# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
