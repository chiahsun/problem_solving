class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        
        var E = Array(repeating: 0, count: prices.count)
        var H = Array(repeating: (0, 0), count: prices.count)
        var S = Array(repeating: 0, count: prices.count)
        
        E[0] = 0
        H[0] = (0, prices[0])
        S[0] = 0
        
        for i in 1..<prices.count {
            let x = prices[i]
            E[i] = max(E[i-1], S[i-1])
            if H[i-1].1 - x > H[i-1].0 - E[i-1] {
                H[i] = (E[i-1], x)
            } else {
                H[i] = H[i-1]
            }
            S[i] = (H[i-1].0 + prices[i] - H[i-1].1)
        }
        
        return max(E.last!, H.last!.0, S.last!)
    }
}