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
        let source = k-1
        d[source] = 0
        var q = ArraySlice([source])
        var s: Set<Int> = []
        for i in 0..<(n-1) {
            while let v = q.first {
                q = q.dropFirst()
                for e in adj[v] {
                    let newCost = d[v] + e.cost
                    if d[e.to] > newCost {
                        d[e.to] = newCost
                        s.insert(e.to)
                    }
                }
            }
            if s.isEmpty { break }
            q = ArraySlice(Array(s))
        }
        return d.isEmpty ? 0 : (d.max()! == Int.max ? -1 : d.max()!)
    }
}