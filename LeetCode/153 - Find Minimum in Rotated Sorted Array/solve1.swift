class Solution {
    func findMin(_ nums: [Int]) -> Int {
        var (i, k) = (0, nums.count-1)
        
        while i < k {
            let mid = (i+k)/2
            let (a, b, c) = (nums[i], nums[mid], nums[k])
            if b > c {
                i = mid+1
            } else {
                k = mid
            }
        }
        return nums[i]
    }
}