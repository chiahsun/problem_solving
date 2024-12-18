class Solution {
    func minPathSum(_ grid: [[Int]]) -> Int {
        var A = grid
        var options: [Int] = []
        for i in 0..<grid.count {
            for k in 0..<grid[0].count {
                options.removeAll()
                if i-1 >= 0 { options.append(A[i-1][k]) }
                if k-1 >= 0 { options.append(A[i][k-1]) }
                A[i][k] += options.min() ?? 0
            }
        }
        return A.last!.last!
    }
}
