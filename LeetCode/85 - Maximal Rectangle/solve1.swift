class Solution {
    func computeLargestRectangle(_ A: [Int]) -> Int {
        var S: [(Int, Int)] = []
        var ans = 0

        for i in 0..<A.count {
            let a = A[i]

            var removeHead: Int?
            while !S.isEmpty && S.last!.0 > a {
                removeHead = S.removeLast().1
            }
            if let head = removeHead {
                S.append((a, head))
            } else {
                S.append((a, i))
            }
            for s in S {
                ans = max(ans, (i - s.1+1) * s.0)
            }
        }
        return ans
    }
    
    func maximalRectangle(_ matrix: [[Character]]) -> Int {
        let M = matrix.count
        guard M > 0 else { return 0 }
        
        let N = matrix[0].count
        var A = Array(repeating: 0, count: N)
        var ans = 0
        for i in 0..<M {
            for k in 0..<N {
                A[k] = (matrix[i][k] == "0") ? 0 : (A[k]+1)
            }
            ans = max(ans, computeLargestRectangle(A))
        }
        return ans
    }
}

// 1   1
// 1   1 1 1
// 1 1 1 1 1

// 3 1 3 2 2


// [3:0] [1:0] [1:0,3:2] [1:0,2:2] [1:0,2:2]