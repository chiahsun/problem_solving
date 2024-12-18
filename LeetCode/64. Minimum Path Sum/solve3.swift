class Solution {
    func minPathSum(_ grid: [[Int]]) -> Int {
        var A = grid

        for i in 1..<grid.count { A[i][0] += A[i-1][0] }
        for i in 1..<grid[0].count { A[0][i] += A[0][i-1] }
        
        for i in 1..<grid.count {
            for k in 1..<grid[0].count {
                A[i][k] += min(A[i-1][k], A[i][k-1])
            }
        }
        return A.last!.last!
    }
}