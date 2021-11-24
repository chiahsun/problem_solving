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
        if matrix[p][k] == target { return true }
        i = p
    
        while i < M {
            if target < matrix[i][0] { return false }
            (p, q) = (0, k)
            while p < q {
                let mid = (p+q)/2
                let midVal = matrix[i][mid]
                if midVal == target { return true }
                if midVal < target { p = mid+1 }
                else               { q = mid }
            }
            if matrix[i][p] == target { return true }
            i += 1
        }
        
        return false
    }
}