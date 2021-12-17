class Solution {
    func maximalSquare(_ matrix: [[Character]]) -> Int {
        let M = matrix.count
        let N = matrix[0].count
        var A = Array(repeating: 0, count: N)
        var nextA = Array(repeating: 0, count: N)
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
                    nextA[k] = max(1, min(i > 0 && k > 0 ? A[k-1]+1 : 0, iw, kw)) 
                    ans = max(ans, nextA[k])
                } else {
                    sumI[k] = 0
                    kw = 0
                    nextA[k] = 0
                }
            }
            A = nextA
        }
        return ans*ans
    }
}