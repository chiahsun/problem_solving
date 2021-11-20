class Solution {
    func cc(_ dp: inout [Int: Int], _ coins: [Int], _ amount: Int) -> Int {
        if amount == 0 { return 0 }
        if let mapped = dp[amount] {
            return mapped
        }
        
        var ans = -1
        for c in coins {
            // amount - c == 0 handled in mapped
            if amount - c > 0 {
                var prev = cc(&dp, coins, amount - c) 
                if prev != -1 {
                    ans = (ans == -1) ? (1+prev) : min(1 + prev, ans)    
                }     
            }
        }
        dp[amount] = ans
        
        return ans
    }
    

    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        var coins = coins.filter { $0 <= amount }
        
        var dp: [Int: Int] = [:]
        for c in coins { dp[c] = 1 }
        
        return cc(&dp, coins, amount)
    }
}