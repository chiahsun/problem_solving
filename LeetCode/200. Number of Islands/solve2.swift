class Solution {
    func dfs(_ startX: Int, _ startY: Int, _ M: Int, _ N: Int, _ A: inout [[Character]]) {
        var st: [(Int, Int)] = [(startX, startY)]
        let dx = [-1, 1, 0, 0]
        let dy = [0, 0, -1, 1]

        while let (x, y) = st.popLast() {
            if A[x][y] == "1" {
                A[x][y] = "0"

                for i in 0..<dx.count {
                    let (nx, ny) = (x + dx[i],  y + dy[i])
                    if nx >= 0 && nx < M && ny >= 0 && ny < N && A[nx][ny] == "1" {
                        st.append((nx, ny))
                    }
                }    
            }
        }
    }

    func numIslands(_ grid: [[Character]]) -> Int {
        var A = grid
        var ans = 0
        
        let (M, N) = (A.count, A[0].count)
        for i in 0..<M {
            for k in 0..<N where A[i][k] == "1" {
                ans += 1
                dfs(i, k, M, N, &A)
            }
        }
        return ans
    }
}