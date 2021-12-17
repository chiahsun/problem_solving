class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var end = nums.count-1
        var i = 0
        while i <= end {
            if nums[i] == val {
                if i != end {
                    (nums[i], nums[end]) = (nums[end], nums[i])
                }
                nums.removeLast()
                end -= 1
            } else {
                i += 1    
            }
        }
        return nums.count
    }
}