class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var preMax = nums[0]
        var allMax = nums[0]
        for i in 1..<nums.count {
            let x = nums[i]
            preMax = max(preMax + x, x)
            allMax = max(allMax, preMax)
        }
        return allMax
    }
}