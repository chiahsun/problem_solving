class Solution {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var end = 0
        for a in nums {
            if a != val {
                nums[end] = a
                end += 1
            }
        }
        return end
    }
}