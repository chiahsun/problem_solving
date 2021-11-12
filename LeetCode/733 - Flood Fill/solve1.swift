class Solution {
    func fill(_ A: inout [[Int]], _ x: Int, _ y: Int, _ newColor: Int) {
        let oldColor = A[x][y]
        if oldColor == newColor { return }
        A[x][y] = newColor
        
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        
        for i in 0..<dx.count {
            let (newx, newy) = (x + dx[i], y + dy[i])
            if newx >= 0 && newx < A.count && newy >= 0 && newy < A[0].count && A[newx][newy] == oldColor {
                fill(&A, newx, newy, newColor)
            }
        }
    }
    
    func floodFill(_ image: [[Int]], _ sr: Int, _ sc: Int, _ newColor: Int) -> [[Int]] {
        var ans = image
        fill(&ans, sr, sc, newColor)
        return ans
    }
}