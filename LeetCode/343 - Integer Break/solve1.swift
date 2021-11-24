class Solution {
    //  2  = 1+1: 1x1(v)
    //  3  = 1+2: 1x2(v)  = 1+1+1: 1x1x1
    //  4  = 2+2: 2x2(v)  = 1+1+2: 1x1x2    1+1+1+1: 1x1x1x1
    //  5  = 2+3: 2x3(v)  = 1+2+2: 1x2x2    1+1+1+2: 1x1x1x2
    //  6  = 3+3: 3x3(v)  = 2+2+2: 2x2x2    1+1+2+2: 1x1x2x2
    //  7  = 3+4: 3x4(v)  = 2+2+3: 2x2x3(v) 1+2+2+2: 1x2x2x2
    //  8  = 4+4: 4x4     = 2+3+3: 2x3x3(v) 2+2+2+2: 2x2x2x2
    //  9  = 4+5: 4x5     = 3+3+3: 3x3x3(v) 2+2+2+3: 2x2x2x3
    // 10  = 5+5: 5x5     = 3+3+4: 3x3x4(v) 2+2+3+3: 2x2x3x3(v)
    func search(_ n: Int, _ dp: inout [Int]) -> Int {
        if dp[n] != 0 { return dp[n] }
        
        var cur = 1
        for k in 1..<n {
            cur = max(cur, k * search(n-k, &dp), k*(n-k))
        }
        dp[n] = cur
        return cur
    }
    
    func integerBreak(_ n: Int) -> Int {
        var dp = Array(repeating: 0, count: n+1)
        dp[1] = 1
        search(n, &dp)
        return dp.last!
    }
}