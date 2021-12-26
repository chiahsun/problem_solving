class Solution {
    func makeConnected(_ n: Int, _ connections: [[Int]]) -> Int {
        let E = connections.count
        guard E >= n-1 else { return -1 }
        
        var edges = Array(repeating: [Int](), count: n)
        for conn in connections {
            edges[conn[0]].append(conn[1])
            edges[conn[1]].append(conn[0])
        }
        
        var visited = Array(repeating: false, count: n)
        var nCC = 0 
        func dfs(_ cur: Int) {
            visited[cur] = true
            for adj in edges[cur] {
                if !visited[adj] {
                    dfs(adj)
                }
            }
        }
        for i in 0..<n {
            if !visited[i] {
                nCC += 1
                dfs(i)
            }
        }
        
        return nCC - 1
    }
}