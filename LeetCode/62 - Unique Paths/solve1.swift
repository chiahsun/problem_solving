class Solution {
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        var A = Array(repeating: Array(repeating: 1, count: n), count: m)
        
        for i in 1..<m {
            for k in 1..<n {
                A[i][k] = (i-1 >= 0 ? A[i-1][k] : 0) + (k-1 >= 0 ? A[i][k-1] : 0)
            }
        }
        return A[m-1][n-1]
    }
}