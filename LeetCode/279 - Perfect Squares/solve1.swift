class Solution {
    func search(_ n: Int, _ dp: inout [Int], _ perfectSquares: [Int]) -> Int {
        if n <= 0 { return 0 }
        if dp[n] != 0 { return dp[n] }
        
        var ans = n
        for s in perfectSquares {
            if n-s < 0 { break }
            ans = min(ans, 1 + search(n-s, &dp, perfectSquares))
        }
        dp[n] = ans
        return ans
    }
    
    func numSquares(_ n: Int) -> Int {
        var perfectSquares = (1...100).map { $0 * $0 }
        
        var dp = Array(repeating: 0, count: n + 1)
        search(n, &dp, perfectSquares)
        
        return dp.last!
    }
}