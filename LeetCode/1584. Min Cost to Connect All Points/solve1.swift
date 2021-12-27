class UnionFind {
    var A: [Int] = []
    
    init(_ N: Int) {
        for i in 0..<N { A.append(i) }
    }
    
    func makeUnion(_ a: Int, _ b: Int) {
        var aRoot = findRoot(a)
        var bRoot = findRoot(b)
        if aRoot != bRoot {
            A[aRoot] = bRoot
        }
    }
    
    func findRoot(_ cur: Int) -> Int {
        var parent = A[cur]
        guard parent != cur else { return cur }
        var cur = cur
        while true {
            let grandParent = A[parent]
            if grandParent == parent { break }
            A[cur] = grandParent
            (cur, parent) = (parent, grandParent)
        }
        return parent
    }
}

class Solution {
    func minCostConnectPoints(_ points: [[Int]]) -> Int {
        let N = points.count
        var edges: [(Int, Int, Int)] = []
        for i in 0..<(N-1) {
            for k in (i+1)..<N {
                let w = abs(points[i][0] - points[k][0]) + abs(points[i][1] - points[k][1])
                edges.append((i, k, w))
            }
        }
        edges = edges.sorted { $0.2 < $1.2 }
        // print(edges)
        var uf = UnionFind(N)
        var E = 0
        var ans = 0
        for e in edges {
            let (u, v, w) = e
            if uf.findRoot(u) != uf.findRoot(v) {
                ans += w
                uf.makeUnion(u, v)
                E += 1
            }
            if E+1 == N {
                break
            }
        }
        
        return ans
    }
}