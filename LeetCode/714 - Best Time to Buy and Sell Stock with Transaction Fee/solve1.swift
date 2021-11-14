class Solution {
    func maxProfit(_ prices: [Int], _ fee: Int) -> Int {
        var a = prices[0]
        var b = a
        
        var ans = 0
        for i in 1..<prices.count {
            let x = prices[i]
            
            if x < b-fee {
                ans += max(0, (b - a - fee))
                a = x
                b = x
            } else if x < a {
                a = x
                b = x
            } else if x > b {
                b = x
            }
        }
        ans += max(0, (b - a - fee))
        return ans
    }
}