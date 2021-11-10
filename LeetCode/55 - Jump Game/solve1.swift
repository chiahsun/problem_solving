class Solution {
    func canJump(_ nums: [Int]) -> Bool {
        var size = 1
        var i = 0
        while i < size && size < nums.count {
            size = max(size, i+nums[i]+1)
            i += 1
        }
        return size >= nums.count
    }
}