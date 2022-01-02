class Solution {
    func numPairsDivisibleBy60(_ time: [Int]) -> Int {
        var m = Array(repeating: 0, count: 60)
        time.forEach { m[$0%60] += 1 }
        var ans = 0
        if case let a = m[0], a > 0 { ans += a*(a-1)/2 }
        if case let a = m[30], a > 0 { ans += a*(a-1)/2 }
        for i in 1..<30  {
            if case let a = m[i], a > 0
             , case let b = m[60-i], b > 0 {
                ans += a * b
            }
        }
        return ans
    }
}