class Solution {
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        var A = Array(repeating: Array(repeating: 1, count: n), count: m)
        
        for i in 1..<m {
            for k in 1..<n {
                A[i][k] = A[i-1][k] + A[i][k-1]
            }
        }
        return A[m-1][n-1]
    }
}