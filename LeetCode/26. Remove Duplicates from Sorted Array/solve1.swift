class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var end = 0
        var prev = -101
        for a in nums {
            if a != prev {
                nums[end] = a
                end += 1
                prev = a
            }
        }
        return end
    }
}