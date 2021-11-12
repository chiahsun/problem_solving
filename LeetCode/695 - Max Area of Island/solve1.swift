class Solution {
    func fill(_ A: inout [[Int]], _ x: Int, _ y: Int) -> Int {
        if A[x][y] == 0 { return 0 }
        var cur = 1
        A[x][y] = 0
        
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        for i in 0..<dx.count {
            let (newx, newy) = (x + dx[i], y + dy[i])
            if newx >= 0 && newx < A.count && newy >= 0 && newy < A[0].count && A[newx][newy] == 1 {
                cur += fill(&A, newx, newy)
            }
        }
        return cur
    }
    
    func maxAreaOfIsland(_ grid: [[Int]]) -> Int {
        var A = grid
        var ans = 0
        for i in 0..<grid.count {
            for k in 0..<grid[0].count {
                ans = max(ans, fill(&A, i, k))
            }
        }
        return ans
    }
}