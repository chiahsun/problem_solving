class Solution {
    func decompressRLElist(_ nums: [Int]) -> [Int] {
        var ans: [Int] = []
        for i in stride(from: 0, to: nums.count, by: 2) {
            ans += Array(repeating: nums[i+1], count: nums[i])
        }
        return ans
    }
}