class Solution {
    func maxSubarraySumCircular(_ nums: [Int]) -> Int {
        let N = nums.count
        let first = nums[0]
        var (localMin, globalMin, localMax, globalMax, total) = (first, first, first, first, first)
        for i in 1..<N {
            let cur = nums[i]
            total += cur
            localMin = cur + (localMin < 0 ? localMin : 0)
            globalMin = min(globalMin, localMin)
            
            localMax = cur + (localMax > 0 ? localMax : 0)
            globalMax = max(globalMax, localMax)
        }
        if total == globalMin {
            return globalMax
        }
        return max(globalMax, total - globalMin)
    }
}