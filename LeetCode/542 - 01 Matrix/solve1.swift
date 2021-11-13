class Solution {
    func updateMatrix(_ mat: [[Int]]) -> [[Int]] {
        var ans = Array(repeating: Array(repeating: -1, count: mat[0].count), count: mat.count)
        
        var q: [(Int, Int)] = []
        
        let M = mat.count
        let N = mat[0].count
        for i in 0..<mat.count {
            for k in 0..<mat[0].count {
                if mat[i][k] == 0 {
                    q.append((i, k))
                    ans[i][k] = 0
                }
            }
        }
        
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        var cur = 1
        while !q.isEmpty {
            var qNext: [(Int, Int)] = []
            
            while !q.isEmpty {
                let (x, y) = q.removeFirst()
                
                for i in 0..<dx.count {
                    let newx = x + dx[i]
                    let newy = y + dy[i]
                    if newx >= 0 && newx < M && newy >= 0 && newy < N,
                       ans[newx][newy] == -1 {
                        ans[newx][newy] = cur
                        qNext.append((newx, newy))
                    }
                }
            }
            q = qNext
            cur += 1
        }
        
        return ans
    }
}