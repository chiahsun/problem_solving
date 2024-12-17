class Solution {
    func isValidSudoku(_ board: [[Character]]) -> Bool {
        let N = 9
        for i in 0..<N {
            var d1: Set<Character> = []
            for k in 0..<N {
                let now = board[i][k]
                if now != "." {
                    if d1.contains(now) { return false }      
                    d1.insert(now)                    
                }
            }
            var d2: Set<Character> = []
            for k in 0..<N {
                let now = board[k][i]
                if now != "." {
                    if d2.contains(now) { return false }      
                    d2.insert(now)
                }
            }
            var d3: Set<Character> = []
            let xoffset = [0, 3, 6, 0, 3, 6, 0, 3, 6]
            let yoffset = [0, 0, 0, 3, 3, 3, 6, 6, 6]
            for x in 0..<3 {
                for y in 0..<3 {
                    let now = board[x + xoffset[i]][y + yoffset[i]]
                    if now != "." {
                        if d3.contains(now) { return false }      
                        d3.insert(now)
                    }
                }
            }
        }
        return true
    }
}