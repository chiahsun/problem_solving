class Solution {
    
    func maximalSquare(_ matrix: [[Character]]) -> Int {
        var W = Array(repeating: Array(repeating: 0, count: matrix[0].count), count: matrix.count)
        var A = W
        var ans = 0
        var H = W
        for i in 0..<matrix.count {
            for k in 0..<matrix[0].count {
                let cur = matrix[i][k] == "1" ? 1 : 0
                W[i][k] = cur
                H[i][k] = cur
                A[i][k] = cur
                ans = max(ans, cur)
                if k-1 >= 0 && W[i][k] != 0 { W[i][k] += W[i][k-1] }
                if i-1 >= 0 && H[i][k] != 0 { H[i][k] += H[i-1][k] }
            }
        }

        for i in 1..<A.count {
            for k in 1..<A[0].count {
                let prev = A[i-1][k-1]
                A[i][k] = min(W[i][k], H[i][k], prev+1)
                ans = max(ans, A[i][k])
            }
        }
        
        return ans * ans
    }
}