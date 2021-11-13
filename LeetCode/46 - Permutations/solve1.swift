class Solution {
    func swap(_ nums: inout [Int], _ i: Int, _ k: Int) {
        if i != k {
            (nums[i], nums[k]) = (nums[k], nums[i])   
        }
    }
    
    func perm(_ ans: inout [[Int]], _ pos: Int, _ nums: inout [Int]) {
        if pos == nums.count-1 {
            ans.append(nums)
            return
        }
        
        for i in pos..<nums.count {
            swap(&nums, pos, i)
            perm(&ans, pos+1, &nums)
            swap(&nums, pos, i)
        }
    }
    
    func permute(_ nums: [Int]) -> [[Int]] {
        var ans: [[Int]] = []
        var A = nums
        perm(&ans, 0, &A)
        return ans
    }
}