class Solution {
    func jump(_ nums: [Int]) -> Int {
        let N = nums.count
        var dp = Array(repeating: N-1, count: N)
        dp[0] = 0
        for i in 0..<N-1 {
            for k in stride(from: 1, to: nums[i]+1, by: 1) {
                if i+k >= N { break }
                dp[i+k] = min(dp[i+k], dp[i]+1)
            }
        }
        return dp[N-1]
    }
}