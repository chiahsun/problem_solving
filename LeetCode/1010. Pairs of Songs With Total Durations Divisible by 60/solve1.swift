class Solution {
    func numPairsDivisibleBy60(_ time: [Int]) -> Int {
        var m: [Int: Int] = [:]
        for t in time {
            m[t%60, default: 0] += 1
        }
        var ans = 0
        if let a = m[0] { ans += a*(a-1)/2 }
        if let a = m[30] { ans += a*(a-1)/2 }
        for (t, a) in m where t >= 1 && t < 30 {
            if let b = m[60-t] {
                ans += a * b
            }
        }
        return ans
    }
}