
class NumMatrix {
    
    var A: [[Int]] = []

    init(_ matrix: [[Int]]) {
        var R = Array(repeating: Array(repeating: 0, count: matrix[0].count), count: matrix.count)
        A = R
        
        for i in 0..<matrix.count {
            for k in 0..<matrix[0].count {
                R[i][k] = (k-1 >= 0 ? R[i][k-1] : 0) + matrix[i][k]
                A[i][k] = (i-1 >= 0 ? A[i-1][k] : 0) + R[i][k]
            }
        }
        
        
    }
    
    func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {
        return A[row2][col2] - (row1-1 >= 0 ? A[row1-1][col2] : 0) - (col1-1 >= 0 ? A[row2][col1-1] : 0) + ((row1-1 >= 0 && col1-1 >= 0) ? A[row1-1][col1-1] : 0)
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix(matrix)
 * let ret_1: Int = obj.sumRegion(row1, col1, row2, col2)
 */