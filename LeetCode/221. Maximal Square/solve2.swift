class Solution {
    func maximalSquare(_ matrix: [[Character]]) -> Int {
        let M = matrix.count
        let N = matrix[0].count
        var A = Array(repeating: Array(repeating: 0, count: N), count: M)
        var sumI = Array(repeating: 0, count: N)
        var kw = 0
        var ans = 0
        for i in 0..<M {
            for k in 0..<N {
                if k == 0 { kw = 0 }
                if matrix[i][k] == "1" {
                    let iw = i > 0 ? sumI[k]+1 : 1
                    sumI[k] = iw
                    kw += 1
                    A[i][k] = max(1, min(i > 0 && k > 0 ? A[i-1][k-1]+1 : 0, iw, kw))
                    ans = max(ans, A[i][k])
                } else {
                    sumI[k] = 0
                    kw = 0
                }
            }
        }
        return ans*ans
    }
}