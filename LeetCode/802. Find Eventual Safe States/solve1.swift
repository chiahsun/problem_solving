class Solution {
    func eventualSafeNodes(_ graph: [[Int]]) -> [Int] {
        let N = graph.count
        var visited = Array(repeating: 0, count: N)
        
        let processing = 1
        let safe = 2
        let unsafe = 3 // has cycle
        
        func dfs(_ cur: Int) {
            var res = processing
            visited[cur] = processing
            for next in graph[cur] {
                if visited[next] == 0 {
                    dfs(next)
                }
                switch visited[next] {
                    case processing, unsafe:
                        res = unsafe
                    default:
                        break
                }
            }
            res = max(res, safe)
            visited[cur] = res
        }
        for i in 0..<N where visited[i] == 0 { dfs(i) }
        
        return Array(0..<N).filter { visited[$0] == 2 }
    }
}