class Solution {
    func dfs(_ board: inout [[Character]], _ x: Int, _ y: Int) {
        board[x][y] = Character("G")
        
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        
        for i in 0..<dx.count {
            let (nx, ny) = (x+dx[i], y+dy[i])
            if nx >= 0 && nx < board.count && ny >= 0 && ny < board[0].count && board[nx][ny] == "O" {
                dfs(&board, nx, ny)    
            }
        }
    }
    
    func solve(_ board: inout [[Character]]) {
        let M = board.count
        let N = board[0].count
        for i in 0..<M {
            if board[i][0] == "O" { dfs(&board, i, 0) }
            if board[i][N-1] == "O" { dfs(&board, i, N-1) }
        }
        for k in 0..<N {
            if board[0][k] == "O" { dfs(&board, 0, k) }
            if board[M-1][k] == "O" { dfs(&board, M-1, k) }
        }
        
        for i in 0..<M {
            for k in 0..<N {
                if board[i][k] == "O" { board[i][k] = Character("X") }
                if board[i][k] == "G" { board[i][k] = Character("O") }
            }
        }
    }
}