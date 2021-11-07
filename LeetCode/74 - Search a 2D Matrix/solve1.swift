class Solution {
    func getX(_ pos: Int, _ N: Int) -> Int { pos / N }
    func getY(_ pos: Int, _ N: Int) -> Int { pos % N }
    func getVal(_ matrix: [[Int]], _ pos: Int, _ N: Int) -> Int {
        return matrix[getX(pos, N)][getY(pos, N)]
    }
    
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        let M = matrix.count
        let N = matrix[0].count
        var lo = 0
        var hi = M*N-1
        
        if target < matrix[0][0] { return false }
        if target == matrix[0][0] { return true }
        if target > matrix[M-1][N-1] { return false }
        if target == matrix[M-1][N-1] { return true }
        while lo < hi {
            let mid = (lo + hi)/2
            let midVal = getVal(matrix, mid, N)
            
            if (midVal == target) { return true }
            
            if (midVal > target) { 
                hi = mid - 1 
                let val = getVal(matrix, hi, N)
                if (val < target) { return false }
                if (val == target) { return true }
            }
            if (midVal < target) { 
                lo = mid + 1 
                let val = getVal(matrix, lo, N) 
                if (val > target) { return false }
                if (val == target) { return true }
            }
        }
        return false
    }
}