class Solution {
    func change(_ amount: Int, _ coins: [Int]) -> Int {
        guard amount > 0 else { return 1 }
        
        let coins = coins.filter { $0 <= amount }.sorted()
        // print("Coins: \(coins)")
        var dp = Array(repeating: Array(repeating: 0, count: amount+1), count: coins.count)
        for i in 0..<coins.count { dp[i][0] = 1 }
        for k in 0..<amount+1 { dp[0][k] = 1 }
        

        for i in 0..<coins.count {
            let curCoin = coins[i]
            for k in 1...amount {
                dp[i][k] = (k-curCoin < 0 ? 0 : dp[i][k-curCoin]) + (i > 0 ? dp[i-1][k] : 0)
                // print("i: \(i) k: \(k) dp: \(dp) curCoin: \(curCoin)")
            }
        }
        // print("dp: \(dp)")
        
        return dp[coins.count-1][amount]
    }
}