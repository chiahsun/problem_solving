class Solution {
    func binarySearch(_ A: [Int], _ target: Int, _ i: Int, _ k: Int) -> Bool {
        guard target >= A[i] && target <= A[k] else { return false }
        
        var (i, k) = (i, k)
        while i < k {
            let mid = (i+k)/2
            let midVal = A[mid]
                                        
            if midVal == target {
                return true
            }
            if midVal > target {
                k = mid
            } else {
                i = mid+1
            }
        }
        
        return target == A[i]
    }
    
    func threeSum(_ nums: [Int]) -> [[Int]] {
        let A = nums.sorted()
        let N = A.count
     
        var ans: [[Int]] = []
        var i = 0
        while i < N-2 {
            let a = A[i]

            var k = i+2
            while k < N {
                let b = A[k]
                while k < N && A[k] == b { k += 1 }
                k -= 1
                
                let target = -(a+b)
                var (p, q) = (i+1, k-1)
               
                if binarySearch(A, target, i+1, k-1) {
                    ans.append([a, target, b])
                }
                k += 1
            }
            while i < N-2 && A[i] == a { i += 1 }
        }
        return ans
    }
}