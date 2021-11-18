class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        var A = nums
        
        var i = 0
        while i < A.count {
            let cur = A[i]
            if cur != i+1 && A[cur-1] != cur {
                (A[i], A[cur-1]) = (A[cur-1], A[i])    
            } else {
                i += 1
            }
        }
        
        var ans: [Int] = []
        for i in 0..<A.count {
            if A[i] != i+1 {
                ans.append(i+1)
            }
        }
        
        return ans
    }
}