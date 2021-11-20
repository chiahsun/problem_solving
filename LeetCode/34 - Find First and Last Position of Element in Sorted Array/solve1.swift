class Solution {
        func getGreatestLowerBound(_ nums: [Int], _ target: Int) -> Int {
        var (i, k) = (0, nums.count-1)
        
        while i < k {
            let mid = (i+k+1)/2
            
            if nums[mid] <= target {
                i = mid
            } else {
                k = mid-1
            }
        }
        
        return i
    }
    
    func getLeastUpperBound(_ nums: [Int], _ target: Int) -> Int {
        var (i, k) = (0, nums.count-1)
        
        while i < k {
            let mid = (i+k)/2
            
            if nums[mid] >= target {
                k = mid
            } else {
                i = mid+1
            }
        }
        
        return k
    }
    
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        // https://stackoverflow.com/questions/35415025/using-guard-with-a-non-optional-value-assignment
        guard !nums.isEmpty,
              case let greatestLowerBound = getGreatestLowerBound(nums, target),
              nums[greatestLowerBound] == target else { return [-1, -1] }
        
        return [getLeastUpperBound(nums, target), greatestLowerBound]
    }
}