class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        let M = matrix.count
        let N = matrix[0].count
        
        var (i, k) = (0, N-1)
        
        // Find the least element that > target at the end of the row
        var (p, q) = (0, M-1)
        while p < q {
            let mid = (p+q)/2
            let midVal = matrix[mid][k]
            if midVal == target { return true }
            if midVal < target { p = mid+1 }
            else               { q = mid }
        }
        i = p
    
        while i < M {
            while k < N && k >= 0 {
                if matrix[i][k] == target     { return true }
                else if matrix[i][k] > target { k -= 1 }
                else                          { break }
            }
            if k < 0 { return false }
            k += 1
            i += 1
        }
        
        return false
    }
}