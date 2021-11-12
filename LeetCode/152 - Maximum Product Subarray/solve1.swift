class Solution {
    
    func maxProduct(_ nums: [Int]) -> Int {
        let N = nums.count
        var first = nums[0]
        var (ans, L, R) = (first, first, first)
        
        for i in 1..<N {
            let val = nums[i]
            (L, R) = (min(val, val * L, val * R), max(val, val * L, val * R))
            ans = max(ans, R)
        }
        return ans
    }
}