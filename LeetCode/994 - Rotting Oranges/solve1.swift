class Solution {
    func orangesRotting(_ grid: [[Int]]) -> Int {
        var A = grid
        
        var q: [(Int, Int)] = []
        var nFresh = 0
        let M = A.count
        let N = A[0].count
        for i in 0..<M {
            for k in 0..<N {
                if A[i][k] == 2 {
                    q.append((i, k))   
                } else if A[i][k] == 1 {
                    nFresh += 1
                }
            }
        }
        
        let dx = [0, 0, 1, -1]
        let dy = [1, -1, 0, 0]
        var ans = 0
        while !q.isEmpty && nFresh > 0{
            var qNext: [(Int, Int)] = []
            
            while !q.isEmpty {
                var (x, y) = q.removeLast()
                
                for i in 0..<dx.count {
                    let newx = x + dx[i]
                    let newy = y + dy[i]
                    if newx >= 0 && newx < M && newy >= 0 && newy < N && A[newx][newy] == 1 {
                        A[newx][newy] = 2
                        nFresh -= 1
                        qNext.append((newx, newy))
                    }
                }
            }
            ans += 1
            q = qNext
        }
        return nFresh == 0 ? ans : -1
    }
}