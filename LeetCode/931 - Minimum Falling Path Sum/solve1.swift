class Solution {
    func minFallingPathSum(_ matrix: [[Int]]) -> Int {
        var A = matrix
        
        for i in 1..<A.count {
            for k in 0..<A[0].count {
                var minVal = A[i-1][k]
                if k-1 >= 0 { 
                    minVal = min(minVal, A[i-1][k-1])
                }
                if k+1 < A[0].count { 
                    minVal = min(minVal, A[i-1][k+1]) 
                }
                A[i][k] += minVal
            }
        }
        return A.last!.min()!
    }
}