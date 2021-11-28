class Solution {
    func minSubArrayLen(_ target: Int, _ nums: [Int]) -> Int {
        let N = nums.count
        var ans = N+1

        var acc = 0
        var start = 0
        for i in 0..<N {
            acc += nums[i]
            while acc >= target && start <= i && ans > 1 {
                ans = min(ans, i-start+1)
                acc -= nums[start]
                start += 1
            } 
        }
        
        return (ans > N) ? 0 : ans
    }
}