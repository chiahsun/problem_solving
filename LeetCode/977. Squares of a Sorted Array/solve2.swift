class Solution {
    
    func square(_ x: Int) -> Int { x * x }
    
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var ans: [Int] = Array(repeating: 0, count: nums.count)
        var l = 0
        var r = nums.count-1
        var i = nums.count-1
        while l < r {
            let a = square(nums[l])
            let b = square(nums[r])
            if (a >= b) {
                ans[i] = a
                l += 1
            } else {
                ans[i] = b
                r -= 1
            }
            i -= 1
        }
        ans[i] = square(nums[l])
        return ans
    }
}