class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var end = 0
        for a in nums {
            if a != 0 { 
                nums[end] = a 
                end += 1
            }
        }
        for i in end..<nums.count {
            nums[i] = 0
        }
    }
}