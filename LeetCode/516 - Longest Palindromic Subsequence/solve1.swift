class Solution {
    func longestPalindromeSubseq(_ s: String) -> Int {
        var characters = Array(s)
        
        let N = characters.count
        var A = Array(repeating: Array(repeating: 0, count: N), count: N)
        
        var ans = 1
        for i in 0..<N {
            for k in stride(from: N-1, to: i, by: -1) {
                // print("i: \(i) k: \(k)")
                let val = characters[i] == characters[k] ? 1 : 0
                A[i][k] = max(
                    val,
                    (i-1 >= 0 && k+1 < N) ? A[i-1][k+1] + val : 0,
                    i-1 >= 0 ? A[i-1][k] : 0,
                    k+1 < N ? A[i][k+1] : 0
                )
                ans = max(
                    ans, 
                    2 * A[i][k],
                    i-1 >= 0 ? 2*A[i-1][k]+1 : 0,
                    k+1 < N ? 2*A[i][k+1]+1 : 0
                )
            }
        }
        // print("A \(A)")
        
        return ans
    }
}