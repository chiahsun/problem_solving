class Solution {
    func matrixBlockSum(_ mat: [[Int]], _ k: Int) -> [[Int]] {
        var A = Array(repeating: Array(repeating: 0, count: mat[0].count), count: mat.count)
        var B = A
        
        for i in 0..<mat.count {
            B[i][0] = mat[i][0]
            for k in 1..<mat[0].count {
                B[i][k] = B[i][k-1] + mat[i][k]
            }
        }
        
        let K = k

        for i in 0...K {
            if i >= mat.count { break }
            for k in 0...K {
                if k >= mat[0].count { break }
                A[0][0] += mat[i][k]
            }
        }
        for i in 1..<mat[0].count {
            A[0][i] = A[0][i-1]
            for k in 0...K {
                if i-K-1 >= 0 { A[0][i] -= mat[k][i-K-1] }
                if i+K < A[0].count { A[0][i] += mat[k][i+K] }   
            }
        }
        
        for i in 1..<mat.count {
            for k in 0..<mat[0].count {
                A[i][k] = A[i-1][k]
                if i-K-1 >= 0 {
                    A[i][k] -= B[i-K-1][min(k+K,mat[0].count-1)] - (k-K-1 >= 0 ? B[i-K-1][k-K-1] : 0)
                }
                if i+K < mat.count {
                    A[i][k] += B[i+K][min(k+K,mat[0].count-1)] - (k-K-1 >= 0 ? B[i+K][k-K-1] : 0)
                }
            }
        }
        
        return A
    }
}