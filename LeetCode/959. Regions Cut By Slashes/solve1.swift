// ?/
// /?

// ???????+
// ??????+
// ?????+
// ????+
// ?? +
//

// /\
// \/

// ??+??
// ?+ +?
// +   +
//  + +
//   +

// //
// / 

// ??+?+
// ?+?+
// +?+
// ?+
// +
class Solution {
    func regionsBySlashes(_ grid: [String]) -> Int {
        let N = 5*grid[0].count-(grid[0].count-1)
        var A = Array(repeating: Array(repeating: 0, count: N), count: N)
        // print("N: \(N)")
        for (i, s) in grid.enumerated() {
            for (k, c) in s.enumerated() {
                let x = i * 4
                let y = k * 4
                // print("x: \(x) y: \(y)")
                if c == "/" {
                    A[4+x][y] = -1; A[3+x][1+y] = -1; A[2+x][2+y] = -1; A[1+x][3+y] = -1; A[x][4+y] = -1
                } else if c == "\\" {
                    A[x][y] = -1; A[1+x][1+y] = -1; A[2+x][2+y] = -1; A[3+x][3+y] = -1; A[4+x][4+y] = -1
                }
            }
        }
         
        var ans = 0
        func dfs(_ x: Int, _ y: Int, _ cur: Int) {
            A[x][y] = cur
            
            let dx = [1, -1, 0, 0]
            let dy = [0, 0, 1, -1]
            for i in 0..<dx.count {
                let nx = x+dx[i]
                let ny = y+dy[i]
                if nx >= 0 && nx < N && ny >= 0 && ny < N && A[nx][ny] == 0 {
                    dfs(nx, ny, cur)
                }
            }
        }
        // print("A: \(A)")
        
        for i in 0..<A.count {
            for k in 0..<A[0].count {
                if A[i][k] == 0 {
                    ans += 1
                    dfs(i, k, ans)
                }
            }
        }
        
        return ans
    }
}