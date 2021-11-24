class Solution {
    func dfs(_ nums: [Int], _ left: Int, _ dp: inout [Int]) ->Int {
        if dp[left] != -1 { return dp[left] }
        var cur = 0
        for a in nums where left - a >= 0 {
            cur += dfs(nums, left - a, &dp)
        }
        dp[left] = cur
        return cur
    }
    
    func combinationSum4(_ nums: [Int], _ target: Int) -> Int {
        var dp = Array(repeating: -1, count: target+1)
        dp[0] = 1
        dfs(nums, target, &dp)
        return dp.last!
    }
}