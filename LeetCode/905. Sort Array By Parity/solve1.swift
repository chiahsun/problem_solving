class Solution {
    func sortArrayByParity(_ nums: [Int]) -> [Int] {
        var nums = nums
        var i = 0
        var k = nums.count-1
        while true {
            while k > 0 && nums[k] % 2 == 1 {
                k -= 1
            }
            if i >= k { break }
            if nums[i] % 2 == 1 {
                (nums[i], nums[k]) = (nums[k], nums[i])
                k -= 1
            }
            i += 1
        }
        return nums
    }
}