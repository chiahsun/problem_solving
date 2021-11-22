class Solution {
    // + > > >
    // ^ > > V
    // ^ < V V
    // < < < V
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        let M = matrix.count
        let N = matrix[0].count
        var w = N
        var h = M
        var ans: [Int] = [matrix[0][0]]
        var (i, k) = (0, 0)
        var (w1, h1, w2, h2) = (w-1, h-1, w-1, h-2)
        
        for val in 1..<M*N {
            // print("\(w1) \(h1) \(w2) \(h2)")
            if w1 > 0 {
                k += 1
                ans.append(matrix[i][k])
                w1 -= 1
            } else if h1 > 0 {
                i += 1
                ans.append(matrix[i][k])
                h1 -= 1
            } else if w2 > 0 {
                k -= 1
                ans.append(matrix[i][k])
                w2 -= 1
            } else if h2 > 0 {
                i -= 1
                ans.append(matrix[i][k])
                h2 -= 1
                if (h2 == 0) {
                    h -= 2
                    w -= 2
                    (w1, h1, w2, h2) = (w, h-1, w-1, h-2)
                }
            }
        }
        return ans
    }
}