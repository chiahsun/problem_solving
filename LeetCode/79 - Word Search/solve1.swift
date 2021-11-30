class Solution {
    func dfs(_ x: Int, _ y: Int, _ board: inout [[Character]], _ word: [Character], _ pos: Int) -> Bool {
        if board[x][y] != word[pos] { return false }
        if pos == word.count-1 { return true }
        
        let ori = board[x][y]
        board[x][y] = "+"
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        for i in 0..<dx.count {
            let (nx, ny) = (x+dx[i], y+dy[i])
            if nx >= 0 && nx < board.count && ny >= 0 && ny < board[0].count {
                if dfs(nx, ny, &board, word, pos+1) {
                    return true
                }
            }
        }
        board[x][y] = ori
        return false
    }
    
    func exist(_ board: [[Character]], _ word: String) -> Bool {
        var board = board
        var word = Array(word)
        for i in 0..<board.count {
            for k in 0..<board[0].count {
                if dfs(i, k, &board, word, 0) {
                    return true
                }
            }
        }
        
        return false
    }
}