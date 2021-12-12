class Solution {
    func canPartition(_ nums: [Int]) -> Bool {
        var total = nums.reduce(0, +)
        guard total % 2 == 0 else { return false }

        let requested = total/2
        var dp = Array(repeating: false, count: requested+1)
        dp[0] = true
        var N = 0

        for a in nums {
            for i in stride(from: N, to: -1, by: -1) {
                if dp[i] {
                    let next = i+a
                    if next == requested {
                        return true
                    }
                    if next < requested {
                        N = max(N, next)
                        dp[next] = true
                    } 
                }
            }
        }
        return false 
    }
}