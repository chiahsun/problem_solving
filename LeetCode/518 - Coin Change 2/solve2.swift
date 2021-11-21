class Solution {
    func change(_ amount: Int, _ coins: [Int]) -> Int {
        var dp = Array(repeating: 0, count: amount+1)
        dp[0] = 1

        for coin in coins {
            for k in stride(from: 1, to: amount+1, by: 1) {
                if k-coin >= 0 {
                    dp[k] += dp[k-coin]     
                }
            }
        }
        
        return dp[amount]
    }
}