class Solution {
    // Find the least element that >= x
    func findLeastUpperBound(_ A: inout [Int], _ x: Int) -> Int {
        var l = 0, r = A.count-1
        
        while l < r {
            let mid = (l+r)/2
            
            if (A[mid] == x) { return mid }
            
            if (A[mid] < x) {
                l = mid+1
            } else {
                r = mid
            }
        }
        return r
    }
    
    func lengthOfLIS(_ nums: [Int]) -> Int {
        var A: [Int] = []
        
        var ans = 1
        for x in nums {
            if A.isEmpty || x > A.last! {
                A.append(x)
            } else {
                let pos = findLeastUpperBound(&A, x)        
                if A[pos] != x {
                    A[pos] = x
                }
            }
            
            ans = max(ans, A.count)
        }
        return ans
    }
}