class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        if target < nums.first! { return 0 }
        if target > nums.last! { return nums.count }
        
        var lo = 0
        var hi = nums.count - 1
        while lo < hi {
            let mid = (lo + hi)/2

            if nums[mid] >= target {
                hi = mid
            } else {
                lo = mid+1
            }
        }
        
        return lo
    }
}