class Solution {
    func dfs(_ accounts: [[String]], _ visited: inout [Int], _ pos: Int, _ rep: Int, _ edge: [String: [Int]]) {
        guard visited[pos] == -1 else { return }
        visited[pos] = rep
        
        for i in 1..<accounts[pos].count {
            let email = accounts[pos][i]
            let curEdge = edge[email]!
            for e in curEdge where visited[e] == -1 {
                dfs(accounts, &visited, e, rep, edge)
            }
        }
    }
    
    func accountsMerge(_ accounts: [[String]]) -> [[String]] {
        let N = accounts.count
        var edge: [String: [Int]] = [:]

        for i in 0..<N {
            let account = accounts[i]
            for k in 1..<account.count {
                let email = account[k]
                edge[email, default: []].append(i)
            }
        }
        
        var visited = Array(repeating: -1, count: N)
        for i in 0..<N where visited[i] == -1 {
            dfs(accounts, &visited, i, i, edge)
        }
        
        var res = Array(repeating: [String](), count: N)
        for i in 0..<N {
            let rep = visited[i]
            if res[rep].isEmpty { res[rep].append("") }
            res[rep] += accounts[i][1...]
        }
    
        res.indices.forEach {
            if !res[$0].isEmpty {
                res[$0] = Array(Set(res[$0]))
                res[$0].sort()
                res[$0][0] = accounts[$0][0]
            }
        }
        
        return res.filter { !$0.isEmpty }
    }
}