struct Edge {
    let to: Int
    let cost: Int
}

class Solution {
    func networkDelayTime(_ times: [[Int]], _ n: Int, _ k: Int) -> Int {
        var adj: [[Edge]] = Array(repeating: [], count: n)
        for t in times {
            adj[t[0]-1].append(Edge(to: t[1]-1, cost: t[2]))
        }
        
        var d:[Int] = Array(repeating: Int.max, count: n)
        var updated: [Bool] = Array(repeating: false, count: n)
        let target = k-1
        d[target] = 0
        updated[target] = true
        for i in 0..<(n-1) {
            var nextUpdated: [Bool] = Array(repeating: false, count: n)
            var hasUpdated = false
            for v in 0..<n where updated[v] {
                for e in adj[v] {
                    let newCost = d[v] + e.cost
                    if d[e.to] > newCost {
                        d[e.to] = newCost
                        nextUpdated[e.to] = true
                        hasUpdated = true
                    }
                }
            }
            if !hasUpdated { break }
            updated = nextUpdated
        }
        return d.isEmpty ? 0 : (d.max()! == Int.max ? -1 : d.max()!)
    }
}