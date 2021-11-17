class Solution {
    func matrixBlockSum(_ mat: [[Int]], _ k: Int) -> [[Int]] {
        let K = k
        
        var A = Array(repeating: Array(repeating: 0, count: mat[0].count), count: mat.count)
        var B = A
        var ans = A
        // row sum only
        for i in 0..<mat.count {
            A[i][0] = mat[i][0]
            for k in 1..<mat[0].count {
                A[i][k] = A[i][k-1] + mat[i][k]
            }
        }
        B[0] = A[0]
        // top-left square
        for i in 1..<mat.count {
            for k in 0..<mat[0].count {
                B[i][k] = B[i-1][k] + A[i][k]
            }
        }
      
         for i in 0..<mat.count {
            for k in 0..<mat[0].count {
                ans[i][k] = B[min(i+K, mat.count-1)][min(k+K, mat[0].count-1)]
                ans[i][k] -= (k-K-1 >= 0) ? B[min(i+K, mat.count-1)][k-K-1] : 0
                ans[i][k] -= ((i-K-1 >= 0) ? B[i-K-1][min(k+K, mat[0].count-1)] : 0)
                ans[i][k] += ((i-K-1 >= 0 && k-K-1 >= 0) ? B[i-K-1][k-K-1] : 0)
            }
         }
        
        return ans
    }
}