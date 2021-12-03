class Solution {
    func findRoot(_ id: Int, _ fromEdges: [[Int]]) -> Int {
        var id = id
        while case let froms = fromEdges[id], !froms.isEmpty {
            id = froms[0]
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
        var fromEdges: [[Int]] = Array(repeating: [], count: n)
        for e in edges {
            toEdges[e[0]].append(e[1])
            fromEdges[e[1]].append(e[0])
        }
        
        var visited = Array(repeating: false, count: n)
        var ans: [Int] = []
        for i in 0..<n {
            if !visited[i] {
                let root = findRoot(i, fromEdges)
                ans.append(root)
                dfs(root, &visited, toEdges)
            }
        }
        // ans.sort()
        return ans
    }
}