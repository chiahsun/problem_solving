class Solution {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var lo = 0
        var hi = nums.count-1
        
        while lo <= hi {
            let mid = (lo + hi)/2
            let midVal = nums[mid]
            if midVal == target {
                return mid
            }
            if midVal < target {
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        
        return -1
    }
}