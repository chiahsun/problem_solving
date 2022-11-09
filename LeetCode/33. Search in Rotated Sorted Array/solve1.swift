class Solution {
    func  findMaxdPos(_ nums: [Int]) -> Int {
        var (i, k) = (0, nums.count-1)
        
        while i < k {
            let mid = (i+k)/2
            let (a, b, c) = (nums[i], nums[mid], nums[k])
            
            if a < c { break }
            
            if a < b       { i = mid } 
            else if a == b { k = i }
            else           { k = mid-1 }
        }
        
        return k
    }
    
    func search(_ nums: [Int], _ target: Int) -> Int {
        let maxPos = findMaxdPos(nums)
        
        let N = nums.count
        var (i, k) = ((maxPos+1)%N, maxPos)
        
        while i != k {
            let mid = k < i ? (i+k+N)/2%N : (i+k)/2
            let midVal = nums[mid]
            
            if midVal == target { return mid }
            if midVal > target {
                k = mid
            } else {
                i = (mid+1)%N
            }
        }
        
        return nums[k] == target ? k : -1
    }
}