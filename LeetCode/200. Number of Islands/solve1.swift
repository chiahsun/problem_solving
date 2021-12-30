class Solution {
    func dfs(_ A: inout [[Character]], _ x: Int, _ y: Int) {
        A[x][y] = "0"
        
        let dx = [-1, 1, 0, 0]
        let dy = [0, 0, -1, 1]
        for i in 0..<dx.count {
            let (nx, ny) = (x + dx[i],  y + dy[i])
            if nx >= 0 && nx < A.count && ny >= 0 && ny < A[0].count && A[nx][ny] == "1" {
                dfs(&A, nx, ny)
            }
        }
    }
    
    func numIslands(_ grid: [[Character]]) -> Int {
        var A = grid
        var ans = 0
        
        for i in 0..<A.count {
            for k in 0..<A[0].count where A[i][k] == "1" {
                ans += 1
                dfs(&A, i, k)
            }
        }
        return ans
    }
}