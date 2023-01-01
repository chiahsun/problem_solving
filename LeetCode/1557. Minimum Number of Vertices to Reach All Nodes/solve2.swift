class Solution {
    func findRoot(_ id: Int, _ fromEdge: [Int?]) -> Int {
        var id = id
        while let from = fromEdge[id] {
            id = from
        }
        return id
    }
    
    func dfs(_ root: Int, _ visited: inout [Bool], _ toEdges: [[Int]]) {
        visited[root] = true
        for to in toEdges[root] {
            if !visited[to] {
                dfs(to, &visited, toEdges)
            }
        }
    }
    
    func findSmallestSetOfVertices(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var toEdges: [[Int]] = Array(repeating: [], count: n)
        var fromEdge: [Int?] = Array(repeating: nil, count: n)
        for e in edges {
            toEdges[e[0]].append(e[1])
            fromEdge[e[1]] = e[0]
        }
        
        var visited = Array(repeating: false, count: n)
        var ans: [Int] = []
        for i in 0..<n {
            if !visited[i] {
                let root = findRoot(i, fromEdge)
                ans.append(root)
                dfs(root, &visited, toEdges)
            }
        }
        return ans
    }
}