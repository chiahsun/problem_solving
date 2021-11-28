class Solution {
    func dfs(_ visited: inout [Bool], _ isConnected: [[Int]], _ pos: Int) {
        visited[pos] = true
        for i in 0..<isConnected[pos].count where i != pos && isConnected[pos][i] == 1 && !visited[i] {
            dfs(&visited, isConnected, i)
        }
    }
    
    func findCircleNum(_ isConnected: [[Int]]) -> Int {
        let N = isConnected.count
        
        var visited = Array(repeating: false, count: N)
        var ans = 0
        for i in 0..<N {
            if !visited[i] {
                ans += 1
                dfs(&visited, isConnected, i)
            }
        }
        return ans
    }
}