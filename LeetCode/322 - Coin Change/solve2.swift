class Solution {
    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        var coins = coins.filter { $0 <= amount }
        
        let NOT_FOUND = -1
        var dp = Array(repeating: NOT_FOUND, count: amount+1)
        dp[0] = 0
        for i in 0...amount {
            if dp[i] != NOT_FOUND {
                for c in coins {
                    let next = i+c
                    if next <= amount {
                        dp[next] = (dp[next] == NOT_FOUND) ? (dp[i]+1) : min(dp[next], dp[i]+1)    
                    }
                }        
            }
        }
        
        return dp[amount]
    }
}