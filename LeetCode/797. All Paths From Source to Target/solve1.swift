class Solution {
    func dfs(_ cur: Int, _ graph: [[Int]], _ history: inout [Int], _ ans: inout [[Int]]) {
        history.append(cur)
        defer { history.removeLast() }
        
        if cur == graph.count-1 {
            ans.append(history)
            return
        }
        
        for next in graph[cur] {
            dfs(next, graph, &history, &ans)
        }
    }
    
    func allPathsSourceTarget(_ graph: [[Int]]) -> [[Int]] {
        var history: [Int] = []
        var ans: [[Int]] = []
        
        dfs(0, graph, &history, &ans)
        return ans
    }
}