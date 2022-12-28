class Solution {
    func numberOfArithmeticSlices(_ nums: [Int]) -> Int {
        guard nums.count >= 3 else { return 0 }
        
        var dp = Array(repeating: 0, count: nums.count)
        dp[0] = 1
        dp[1] = 2
        var ans = 0
        for i in 2..<nums.count {
            if nums[i] - nums[i-1] == nums[i-1] - nums[i-2] {
                dp[i] = dp[i-1]+1
            } else {
                dp[i] = 2
                let N = dp[i-1]
                ans += ((N-1)*(N-2)/2)
            }
        }
        
        let N = dp.last!
        ans += ((N-1)*(N-2)/2)
        return ans
    }
}