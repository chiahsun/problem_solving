class Solution {
    func findPeakElement(_ nums: [Int]) -> Int {
        var (i, k) = (0, nums.count-1)
        
        while i < k {
            let mid = (i+k)/2
            let midVal = nums[mid]
            let (a, b, c) = (nums[mid > 1 ? mid-1 : 0], nums[mid], nums[mid+1])
            
            if b == max(a, b, c) { return mid }
            if c > b { i = mid+1 }
            else { k = mid }
        }
        
        return i
    }
}