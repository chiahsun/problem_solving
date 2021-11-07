class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        var best = 0
        var lowest = prices[0]
        for i in 1..<prices.count {
            let x = prices[i]
            best = max(x - lowest, best)
            lowest = min(x, lowest)
        }
        return best
    }
}