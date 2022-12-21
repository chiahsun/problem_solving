class Solution {
    func shortestPathBinaryMatrix(_ grid: [[Int]]) -> Int {
        guard grid[0][0] == 0 else { return -1 }

        var A = grid
        var current: [(Int, Int)] = [(0, 0)]
        var next: [(Int, Int)] = []
        
        let N = A.count
        var ans = 1
        
        let dx = [-1, -1, -1,  0, 0,  1, 1, 1]
        let dy = [-1,  0,  1, -1, 1, -1, 0, 1]
        while !current.isEmpty {
            for (x, y) in current where A[x][y] == 0 {
                A[x][y] = 1
                
                if x == N-1 && y == N-1 { 
                    return ans
                }
            
                for i in 0..<dx.count {
                    let (nx, ny) = (x + dx[i], y + dy[i])
                    if nx >= 0 && nx < N && ny >= 0 && ny < N && A[nx][ny] == 0 {
                        next.append((nx, ny))
                    }
                }         
            }
            current = next
            ans += 1
            next.removeAll()
        }
        
        return -1
    }
}