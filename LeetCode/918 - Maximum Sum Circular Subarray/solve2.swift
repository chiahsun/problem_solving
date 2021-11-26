class Solution {
    func maxSubarraySumCircular(_ nums: [Int]) -> Int {
        let N = nums.count
        let first = nums[0]
        var (localMin, globalMin, localMax, globalMax, total) = (first, first, first, first, first)
        for i in 1..<N {
            let cur = nums[i]
            total += cur
            localMin = min(cur, localMin+cur)
            globalMin = min(globalMin, localMin)
            
            localMax = max(cur, localMax+cur)
            globalMax = max(globalMax, localMax)
        }
        if total == globalMin {
            return globalMax
        }
        return max(globalMax, total - globalMin)
    }
}