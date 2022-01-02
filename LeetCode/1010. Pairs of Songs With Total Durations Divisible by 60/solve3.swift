class Solution {
    func numPairsDivisibleBy60(_ time: [Int]) -> Int {
        var cnt = Array(repeating: 0, count: 60)
        var ans = 0
        for t in time {
            let cur = t % 60
            let prev = (60 - cur) % 60
            ans += cnt[prev]
            cnt[cur] += 1
        }
        return ans
    }
}