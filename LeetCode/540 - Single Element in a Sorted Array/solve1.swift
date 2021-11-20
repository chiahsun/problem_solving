class Solution {
    func singleNonDuplicate(_ nums: [Int]) -> Int {
        let N = nums.count
        var (i, k) = (0, N-1)
        
        while i < k {
            let mid = (i+k)/2
            let (a, b, c) = (nums[mid-1], nums[mid], nums[mid+1])
            if a != b && b != c { 
                i = mid
                break
            }
            
            if b == c {
                if mid % 2 == 1 {
                    k = mid-1
                } else {
                    i = mid+2
                }
            } else {
                if (N-mid) % 2 == 0 {
                    i = mid+1
                } else {
                    k = mid-2
                }
            }
        }
        return nums[i]
    }
}