class Solution {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        let M = matrix.count
        let N = matrix[0].count
        
        var (i, k) = (0, N-1)
        
        // binary search?
        while i < M {
            if matrix[i][k] < target { i += 1 }
            else if matrix[i][k] == target { return true }
            else { break }
        }
    
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