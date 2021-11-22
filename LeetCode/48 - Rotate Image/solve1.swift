class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        let N = matrix.count
        let M = N/2
        for i in 0..<N/2 {
            for k in 0..<(N+1)/2 {
                let sx = k - M
                let sy = -(i - M)
                var (x, y) = (sx, sy)
                var backup = matrix[i][k]
                repeat {
                    var (nx, ny) = (y, -x)
                    var (i, k) = (M-ny, M+nx)
                    if N % 2 == 0 {
                        if i > M { i -= 1 }
                        if k > M { k -= 1 }
                    }
                    (matrix[i][k], backup) = (backup, matrix[i][k])
                    (x, y) = (nx, ny)
                } while (x != sx || y != sy)
            }
        }
    }
}