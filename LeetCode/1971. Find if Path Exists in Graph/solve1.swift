class Solution {
    func validPath(_ n: Int, _ edges: [[Int]], _ start: Int, _ end: Int) -> Bool {
        var E = Array(repeating: [Int](), count: n)
        for e in edges {
            E[e[0]].append(e[1])
            E[e[1]].append(e[0])
        }
        
        var ids = Array(repeating: -1, count: n)
        func dfs(_ cur: Int, _ id: Int) {
            ids[cur] = id
            for adj in E[cur] {
                if ids[adj] == -1 {
                    dfs(adj, id)
                }
            }
        }
        
        for i in 0..<n {
            if ids[i] == -1 {
                dfs(i, i)
            }
        }
        
        return ids[start] == ids[end]
    }
}