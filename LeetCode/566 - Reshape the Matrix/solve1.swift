class Solution {
    func matrixReshape(_ mat: [[Int]], _ r: Int, _ c: Int) -> [[Int]] {
        let m = mat.count
        let n = mat[0].count
        if m * n != r * c { return mat }
        
        var ans = Array(repeating: Array(repeating: 0, count: c), count: r)
        var p = 0
        var q = 0
        for i in 0..<m {
            for k in 0..<n {
                ans[p][q] = mat[i][k]
                q += 1
                if (q == c) {
                    p += 1
                    q = 0
                }
            }
        }
        return ans
    }
}