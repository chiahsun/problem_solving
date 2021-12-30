class UnionFind {
    var id: [Int]
    var count: [Int]
    
    init(_ N: Int) { id = Array(0..<N); count = Array(repeating: 1, count: N) }
    
    func makeUnion(_ a: Int, _ b: Int) {
        var ra = findRoot(a)
        var rb = findRoot(b)
        if ra != rb {
            if count[ra] < count[rb] { swap(&ra, &rb) }
            id[rb] = ra; 
            count[ra] += count[rb] 
        }
    }
    
    func findRoot(_ a: Int) -> Int {
        guard case let parent = id[a], parent != a else { return a }
        let ra = findRoot(parent)
        id[a] = ra
        return ra
    }
}

class Solution {
    func numIslands(_ grid: [[Character]]) -> Int {
        let M = grid.count
        let N = grid[0].count
                
        var ids = Array(repeating: Array(repeating: 0, count: N), count: M)
        var id = 0
        for i in 0..<M {
            for k in 0..<N {
                if grid[i][k] == "1" {
                    ids[i][k] = id
                    id += 1
                }
            }
        }
        
        var uf = UnionFind(id)
        for i in 0..<M {
            for k in 0..<N where grid[i][k] == "1" {
                if i+1 < M && grid[i+1][k] == "1" {
                    uf.makeUnion(ids[i][k], ids[i+1][k])
                }
                if k+1 < N && grid[i][k+1] == "1" {
                    uf.makeUnion(ids[i][k], ids[i][k+1])
                }
            }
        }
        var s : Set<Int> = []
        for i in 0..<M {
            for k in 0..<N where grid[i][k] == "1" {
                s.insert(uf.findRoot(ids[i][k]))
            }
        }
        return s.count
    }
}