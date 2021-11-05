class Solution {
    func maximumWealth(_ accounts: [[Int]]) -> Int {
        var ans = 0
        for arr in accounts {
            var cur = arr.reduce(0, +)
            ans = max(ans, cur)
        }
        return ans
    }
}